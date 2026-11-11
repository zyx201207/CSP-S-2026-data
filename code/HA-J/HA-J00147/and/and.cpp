#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m;
	long long ans=0;
	cin>>n>>m;
	long long a[n+5];
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m==1){
		sort(a+1,a+n+1);
		cout<<a[n];
	}else if(m==2&&n<=10000){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++)
				ans=max(ans,a[i]&a[j]);
		}
		cout<<ans;
	}else if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++)ans&=a[i];
		cout<<ans;
	}else if(m==n-1&&n<=10000){
		for(int i=1;i<=n;i++){
			long long x=2^31-1;
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				x&=a[j];
			}
			ans=max(ans,x);
		}
		cout<<ans;
	}else if(m==3&&n<=900){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				for(int k=j+1;k<=n;k++){
					ans=max(ans,a[i]&a[j]&a[k]);
				}
			}
		}
		cout<<ans;
	}else{
		sort(a+1,a+n+1);
		bool f=1;
		for(int i=1;i<=n;i++){
			if(a[i]&(a[i]+1)!=0)f=0;
		}
		if(f)cout<<a[n-m+1];
		else{
			ans=a[n];
			for(int i=n-1;i>=n-m+1;i--)ans&=a[i];
			cout<<ans;
		}
	}
	return 0;
}
