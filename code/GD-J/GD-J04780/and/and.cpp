#include <bits/stdc++.h>
using namespace std;
int a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(m==1){
		cout<<a[n];
		return 0;
	}
	else if(m==2){
		int maxx=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				maxx=max(maxx,i&j);
			}
		}
		cout<<maxx;
		return 0;
	}
	else if(m==n){
		long long ans=a[1];
		for(int i=1;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	else if(m==n-1){
		int maxx=0;
		long long ans=a[1];
		for(int i=1;i<=n;i++){
			ans=ans&a[i];
		}
		for(int i=1;i<=n;i++){
			int ans1=ans;
			ans1=ans|a[i];
			maxx=max(maxx,ans1);
		}
		cout<<maxx;
		return 0;
	}
	long long ans=a[n];
	for(long long i=1;i<=m;i++){
		ans=ans&a[n-i+1];
	}
	cout<<ans;
	return 0;
}
