#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,m,a[N],maxx,cnt;
void dfs(int u,int s,int l){
	if(l==m){
		maxx=max(maxx,u);
		return;
	}
	if(u<=maxx)
		return;
	for(int i=s;i<=n;i++)
		if(l==0)
			dfs(a[i],i+1,l+1);
		else
			dfs(u&a[i],i+1,l+1);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(m==1){
		sort(a+1,a+n+1);
		cout<<a[n];
		return 0;
	}
	else if(m==n){
		cnt=a[1];
		for(int i=2;i<=n;i++)
			cnt&=a[i];
		cout<<cnt;
		return 0;
	}
	dfs(1,1,0);
	cout<<maxx;
	return 0;
}
