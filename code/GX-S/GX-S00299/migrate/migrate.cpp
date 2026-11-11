#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e6+10;
vector<int> tl[N],tr[N];
long long lval,a[N],pre[N],ans,t;
int l,c;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		int n;
		ll d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		ll st=upper_bound(a+1,a+n+1,d+a[1])-a-1;
		lval=a[(int)st-1];
		for(int i=st;i<=n;i++)
		{
			while(lval+a[i]-a[i-1]>d)
			{
				l++;
				lval-=(a[l]-a[l-1]);
			}
			lval+=a[i]-a[i-1];
			tl[l].push_back(i);
			tr[i].push_back(l);
		}
		for(int i=1;i<=n;i++)
		{
			ans+=tr[i].size()*tl[i-1].size();
			tr[i].clear();
			tl[i].clear();
		}
		cout<<ans/2<<"\n";
	}
	return 0;
}
/*0 2
4 2
1 2 3 4
5 2
1 2 3 4 5*/
