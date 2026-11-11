#include<bits/stdc++.h>
using namespace std;
int n,m,f;
long long a[200005],sum,sum1,cnt,l=2;
long long yh,maxx;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1){
			yh=a[i];
		}else{
			yh&=a[i];
		}
	}
	if(m==1){
		cout<<a[1];
		f=1;
	}
	if(m==n){
		cout<<yh;
		f=1;
	}
	if(m==2&&n<=2000){
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				maxx=max(maxx,a[i]&a[j]);
			}
		}
		cout<<maxx;
		f=1;
	}
	if(f==0){
		sort(a+1,a+1+n,greater<long long>());
		while(sum==0){
			cnt=0;
			sum=a[l-1];
			for(int i=l;i<=m+cnt;i++){
				sum1=sum;
				sum&=a[i];
				if(sum==0&&cnt<=n-m){
					sum=sum1;
					cnt++;
				}
			}
			l++;
		}
		
		cout<<sum;
	}
	
	return 0;
} 
