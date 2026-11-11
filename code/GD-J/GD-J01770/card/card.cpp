#include<bits/stdc++.h>
using namespace std;
int n,m,mp[300005],num,fr=1,mum[500005],ans[300005];
map<int,int> mp1;
bool use[300005];
int main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++) cin>>mum[i];
	for (int j=1;j<=n;j++)
	{
		memset(mp,0,sizeof(mp));
		fr=1;
		for (int i=j;i<=n;i++){
			num=mum[i];
			if (!use[num]){
				mp[fr++]=num;
				mp1[num]=fr-1;
			}
			else
			{
				use[num]=!use[num];
				fr=use[num]+1;
			}
		}
		for (int i=1;i<fr;i++)
		{
			ans[mp[i]]++;
		}
	}
	for (int i=1;i<=m;i++) cout<<ans[i]<<" ";
	return 0;
}
