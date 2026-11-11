#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int nxt[maxn][30],pos[maxn],ans[maxn];
int n,m,a[maxn];
void pre_work()
{
	for(int i=1;i<=n;i++)
	{
		if(pos[a[i]])nxt[pos[a[i]]][0]=i;
		pos[a[i]]=i;
	}
	for(int i=1;i<=log2(n);i++)
	{
		for(int j=1;j<=n;j++)
		nxt[j][i]=nxt[nxt[j][i-1]][i-1];
	}
}
void solve(int l)
{
	for(int i=l;i<=n;i++)
	{
		if(nxt[i][0]){
			int k=0;
			while(nxt[i][k])k++;
			i=nxt[i][k-1]-1;
			continue;
		}
		ans[a[i]]++;
	}
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0); 
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	pre_work();
	for(int i=1;i<=n;i++){
		solve(i);
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<" ";
	return 0;
}
