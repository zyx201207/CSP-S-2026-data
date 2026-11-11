#include<bits/stdc++.h>
using namespace std;
long long n,m,cnt,ans=1,yuan=0,shen=0,qidong=0;
bool f1=0,f2=0;
long long a[500005],d[500005],sum[500005],num[500005],k[500005],yun[500005],duo[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
		if(i>=2&&!f2){
			yun[i]=yun[i-1]+(a[i]-a[i-1])*(i-1);
//			cout<<yun[i]<<endl;
			duo[yun[i]]=i;
		}
		if(a[i]==i&&!f1){
			yuan++;
		}
		else f1=1;
		if(i==2){
			qidong=a[i]-a[i-1];
		}
		if(a[i]-a[i-1]==qidong&&!f2){
			shen++;
		}
		else f2=1;
	}
	
	
//	for(long long i=1;i<=15;i++){
//		cout<<duo[i]<<endl<<endl;
//	}
	
	if(yuan>=n){ //A
		int yuanshi=1;
		while(m){
			m-=yuanshi;
			if(m>=0)ans++;
			else break;
			yuanshi++;
		}
		cout<<min(n,ans);
		return 0;
	}
	else if(shen>=n-2){ //B
		while(m){
			if(duo[m]>0){
				cout<<min(n,duo[m]);
				return 0;
			}
			else m--;
//			cout<<ans<<endl;
		}
		cout<<min(n,ans);
		return 0;
	}
	sort(a+1,a+n+1);
	for(long long i=2;i<=n;i++){
		d[i]=a[i]-a[i-1];
		sum[i]=sum[i-1]+d[i]*(i-1);
	}
	cnt=sum[n];
	for(long long i=n-1;i>=1;i--){
		num[i]+=num[i+1]+a[n]-a[i];
		if(sum[i]>m)k[i]=i;
		else k[i]=n;
//		cout<<k[i]<<endl;
	}
	for(long long i=1;i<n-ans+1;i++){
		for(long long j=k[i];j>i+ans-1;j--){
//			cout<<i<<" "<<ans<<endl;
			if(sum[j]+num[i]-cnt+(i-1)*(a[n]-a[j])<=m){
				ans=max(ans,j-i+1);
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}

