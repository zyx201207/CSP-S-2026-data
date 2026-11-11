#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;
ll n,m,a[N],b[N],d=-1e18;
void dfs(int s,int p){
	if(s>=m){
		ll p=a[b[0]];
		for(int i=1;i<m;i++)p&=a[b[i]];
		d=max(d,p);
		return ;
	}
	for(int i=p;i<=n;i++){
		b[s]=i;
		dfs(s+1,i+1);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	dfs(0,1);
	cout<<d;
	return 0;
}
//4 2 3 15 12 12
