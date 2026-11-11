#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(n==m){
		long long ans=0,x;
		cin>>ans;
		for(int i=2;i<=n;i++){
			cin>>x;
			ans&=x;
		}
		cout<<ans;
		return 0;
	}
	if(m==1){
		long long x,ans=INT_MIN;
		for(int i=1;i<=n;i++){
			cin>>x;
			ans=max(x,ans);
		}
		cout<<ans;
		return 0;
	}
	if(m==2){
		int ans=INT_MIN,a[N];
		for(int i=1;i<=n;i++)cin>>a[i];
		for(int i=1;i<n;i++)for(int j=i+1;j<=n;j++)ans=max(int(a[i]&a[j]),ans);
		cout<<ans;
		return 0;
	}
	return 0;
}

