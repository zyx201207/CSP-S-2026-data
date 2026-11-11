#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,a[500010],ans[300010],app[300010];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i],app[a[i]]=i;
	for(int i=1;i<=n;i++)for(int j=i;j<=n;j++)ans[a[j]]++,j=app[a[j]];
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}
