#include<bits/stdc++.h>
using namespace std;
int n,fa=1,fb=1;
long long m,a[500010],num[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i) fa=0;
		if(i>=3&&a[i]-a[i-1]!=a[i-1]-a[i-2]) fb=0;
	}
	if(m==0){
		cout<<1;
		return 0;
	}
	sort(a+1,a+1+n);
	if(fa||fb){
		long long ans=1;
		for(int i=n-1;i>=1;i--){
			if(m<a[n]-a[i]) break;
			m-=(a[n]-a[i]);
			ans++;
		}
		cout<<ans;
		return 0;
	}
	//if(n<=16||m<=1000){
		long long sum,ans=1,mm=m;
		for(int i=2;i<=n;i++){	
			m=mm,sum=1;
			if(a[i]!=a[i+1]){
				for(int j=i-1;j>=1;j--){
					if(m<a[i]-a[j]) break;
					m-=(a[i]-a[j]);
					sum++;
				}
				ans=max(ans,sum);
			}
				
		}
		cout<<ans;
		return 0;
	//}
	return 0;
} 
