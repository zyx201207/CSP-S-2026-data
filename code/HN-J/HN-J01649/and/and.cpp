#include<bits/stdc++.h>
using namespace std;
#define int long long
int an[200010];
int maxn=0;
int n,m;
void dfs(int dt,int xz,int ad){
	if(xz>=m){
		maxn=max(maxn,ad);
		return;
	}
	if(dt>=n)return;
	dfs(dt+1,xz+1,ad&an[dt+1]);
	dfs(dt+1,xz,ad);
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>an[i];
	dfs(0,0,1073741823);
	cout<<maxn;
	return 0;
} 
