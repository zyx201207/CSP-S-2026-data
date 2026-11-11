#include <bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int n,m,a[N],s[N],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int x=i;
		for(int j=20;j>=0;j--){
			int nx=(x-(1<<j));
			if(nx<0)continue;
			if(a[i]*(i-nx)-(s[i]-s[nx])<=m)x=nx;
		}
		ans=max(ans,i-x);
	}
	cout<<ans;
	return 0;
}
