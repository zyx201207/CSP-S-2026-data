#include <bits/stdc++.h>
using namespace std;
struct stu
{
	int i,t;
};
int c,n,m,d,q,w[500005],k[25];
stu a[100005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=0;i<m;i++)
	{
		cin>>w[i];
	}
	cout<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>k[i];
		for(int j=0;j<k[i];j++)
		{
			cin>>a[j].i>>a[j].t;
		}
		cout<<endl;
	}
	while(q--)
	{
		int x,y;
		long long ans=0;
		cin>>c>>y;
		ans+=w[x];
		if(c>=6&&c<=11)
		{
			while(x!=y)
			{
				ans+=a[x].t;
				x=a[x].i;
			}
			ans+=a[x].t;
		}
		if(c>=12&&c<=19)
		{
			ans+=(a[0].t)*2;
		}
		ans+=w[y];
		cout<<ans<<endl;
	}
	return 0;
}
//0 2 5 20 2
//4 1 9 2 5
//3 1 5 2 7 4 6
//3 2 3 3 4 5 7
//1 3
//1 2
