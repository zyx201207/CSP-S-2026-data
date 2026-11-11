#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+5;
bool f[N];
ll Cyrene[N],latest[N];
int n,m;
void init()
{
	for(int i=1;i<=m;i++) f[i]=false;
	for(int i=1;i<=n;i++) latest[i]=0;
} 
void solve()
{
	cin>>n>>m;
	int ai[N];
	for(int i=1;i<=n;i++) cin>>ai[i];
	for(int i=1;i<=n;i++)
	{
		init();
		for(int j=i;j<=n;j++) 
		{
			if(f[ai[j]]==true)
			{
				for(int k=latest[ai[j]];k<j;k++) 
				{
					latest[ai[k]]=0,f[ai[k]]=false;
				}
				latest[ai[j]]=j; 
			}
			else f[ai[j]]=true,latest[ai[j]]=j;
		}
		for(int j=1;j<=m;j++) if(f[j]) Cyrene[j]++;
	}
	for(int i=1;i<=m;i++) cout<<Cyrene[i]<<' ';
}
int main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int T=1;
	while(T--) solve();
	return 0;	
} 
