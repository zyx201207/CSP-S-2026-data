#include<bits/stdc++.h>
using namespace std;
const int mx=5005;
int n,m;
int lst[mx];
int a[mx];
int cnt[mx];
vector<int>v;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		memset(lst,-1,sizeof(lst));
		for(int j=i;j<=n;j++)
		{
			if(lst[a[j]]!=-1)
			{
				while(v.size()>=lst[a[j]])v.pop_back();
			}
			v.push_back(a[j]);
			lst[a[j]]=v.size();
		}
		while(v.size())
		{
			cnt[v[(int)v.size()-1]]++;
			v.pop_back();
		}
	}
	for(int i=1;i<=m;i++)cout<<cnt[i]<<' ';
	return 0;
}
/*



*/

