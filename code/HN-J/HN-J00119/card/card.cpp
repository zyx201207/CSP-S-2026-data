#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+10;
int a[MAXN],n,m,ans[MAXN],r[MAXN];
unordered_map<int,int> mp;
int main(  )
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int i=1;i<=n;i++) r[i]=0;
		for(int j=i;j<=n;j++)
		{
			mp[a[j]]++;
			if(mp[a[j]]==2)
			{
				int k=j-1;
				while(1)
				{
					if(!r[k]) mp[a[k]]--;
					r[k]=1;
					if(a[k]==a[j]) break;
					k--;
				}
			}
		}
		for(int i=1;i<=m;i++) if(mp[i]>0) ans[i]++,mp[i]=0;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
}
