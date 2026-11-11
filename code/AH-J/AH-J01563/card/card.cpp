#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int Maxn=5e5+5;
const int Maxm=3e5+5;
int a[Maxn];
int ans[Maxm];
int l_Max[Maxn];
int Maxid[Maxm];
int r_id[Maxm];
bool dontchange[Maxm];
bool vis[Maxm];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		l_Max[i]=Maxid[a[i]];
		Maxid[a[i]]=i;
		// cout << l_Max[i] << " ";
	}
	// cout << "\n";
	if(n<=5000)
	{
		for(int i=1;i<=n;i++)
		{
			memset(vis,false,sizeof(vis));
			bitset<Maxn> bt;
			for(int j=i;j<=n;j++)
			{
				if(l_Max[j]>=i && bt[l_Max[j]]!=1)
				{
					for(int k=l_Max[j];k<j;k++)
					{
						bt[k]=1;
					}
				}
			}
			// for(int j=1;j<=n;j++)
			// {
			// 	cout << bt[j];
			// }
			// cout << "\n";
			for(int j=i;j<=n;j++)
			{
				if(bt[j]==0 && !vis[a[j]])
				{
					ans[a[j]]++;
					vis[a[j]]=true;
				}
			}
		}
	}
	else
	{
		int Minwangid=n+5;
		set<int> Maxwangid;
		for(int i=n;i>=1;i--)
		{
			if(Minwangid>i)
			{
				ans[a[i]]=max(ans[a[i]],i);
				dontchange[a[i]]=true;
			}
			if(l_Max[i]!=0) 
			{
				Minwangid=min(Minwangid,l_Max[i]);
			}
			if(!dontchange[a[i]])
			{
				auto it=Maxwangid.lower_bound(i);
				int L;
				if(Minwangid>=i) L=0;
				else L=*(--it);
				// cout << i << " " << L << " " << l_Max[i] << "\n";
				ans[a[i]]+=i-max(L,l_Max[i]);
			}
			if(l_Max[i]!=0) 
			{
				Maxwangid.insert(l_Max[i]);
			}
		}
	}
	// cout << "\n";
	for(int i=1;i<=m;i++)
	{
		cout << ans[i] << " ";
	}
	return 0;
}
