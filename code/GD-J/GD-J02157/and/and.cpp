#include<bits/stdc++.h>
using namespace std;
int n,m,ma=-1,fb=1,fa=-1;
int a[200005],sum[200005],cnt[25],summ[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<=21;i++){
		cnt[i]=pow(2,i);
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
		ma=max(ma,a[i]);
		if(i==1){
			sum[i]=a[i];
		}else{
			sum[i]=(sum[i-1]&a[i]);
		}
		
		if(a[i]!=i-1){
			fb=0;
		}
		if(fa==0) continue;
		int ff=0;
		for(int i=0;i<=21;i++){
			if(a[i]==cnt[i]-1){
				ff=1;
				break;
			}
		}
		fa=ff;
	}//5 3 1 3 7 15 21
	if(m==1){
		cout<<ma;
	}else if(m==n){
		cout<<sum[n];
	}else if(m==2){
		int aans=-1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				aans=max(aans,(a[i]&a[j]));
			}
		}
		cout<<aans;
	}else if(fb==1){
		cout<<n-m;
	}else if(m==n-1){
		int ans=-1;
		summ[n]=a[n];
		for(int i=n-1;i>=1;i--){
			summ[i]=(summ[i+1]&a[i]);
		}
		for(int i=1;i<=n;i++){
			ans=max(ans,(sum[i-1]&summ[i+1]));
		}
		cout<<ans;
	//	cout<<m<<" "<<n;
	}else if(fa==1){
		sort(a+1,a+1+n);
		cout<<a[n-m+1];
	}
	return 0;
}
