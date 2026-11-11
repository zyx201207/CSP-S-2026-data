#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+10;
int c,n,m,d,q;
ll w[N];
struct Node{
	int t,a;
};
vector<Node> num[N];
ll ans;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		int x1,x2;
		for(int j=1;j<=k;j++)
		{
			cin>>x1>>x2;
			Node zzz;
			zzz.a=x1,zzz.t=x2;
			num[i].push_back(zzz);
		}
	}
	while(q--)
	{
		int xr,yr;
		cin>>xr>>yr;
		ll ans1=0;
		ans1+=w[xr];
		ans1+=w[yr];
		int j1=1,j2=1;
		for(int i=1;i<=n;i++)
		{
			bool flag1=false;
			bool flag2=false;
			for(int j=0;j<num[i].size();j++)
			{
				if(num[i][j].a==xr)
				{
					flag1=true;
					j1=j;
				}
				if(num[i][j].a==yr)
				{
					flag2=true;
					j2=j;
				}
				if(flag1&&flag2)
				{
					ans1+=num[i][j1].t;
					ans1+=num[i][j2].t;
					ans=max(ans,ans1);
					break;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
