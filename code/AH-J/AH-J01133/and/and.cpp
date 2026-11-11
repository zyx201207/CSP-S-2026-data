#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ma;
map<long long,map<long long,long long> > vis;
void dfs(long long pos,long long cnt,long long sum){
	if(pos>n){
		if(cnt==m) ma=max(ma,sum);
		return;
	}
	if(vis[pos][cnt]>=sum&&sum!=0) return;
	vis[pos][cnt]=sum;
	dfs(pos+1,cnt,sum);
	if(sum==0&&cnt<m) dfs(pos+1,cnt+1,a[pos]);
	if(sum!=0&&cnt<m) dfs(pos+1,cnt+1,sum&a[pos]);
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	dfs(1,0,0);
	cout<<ma;
	return 0;
}
