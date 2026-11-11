#include <bits/stdc++.h>
using namespace std;
const int N=2e5+7;
int n,m,ans=-1,a[N];
bool v[N];
void dfs(int x,int s,int y){
	v[x]=1;s++;
	y=(a[x]&y);
	if (s==m) ans=max(ans,y);
	else for (int i=x+1;i<=n;i++) if (v[i]==0) dfs(i,s,y);
	s--;
	v[x]=0;
	return ;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>a[i];
	for (int i=1;i<=n-m+1;i++) dfs(i,0,a[i]);
	cout<<ans;
	return 0;
}
