#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
int n,m,a[N],ans[M];
struct u
{
	int id;
	bool f;
}b[M];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(NULL),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		memset(b,0,sizeof(b));
		for(int j=i;j<=n;j++)
		{
			ans[a[j]]++;
			if(b[a[j]].f==1)
			{
				for(int k=b[a[j]].id;k<j;k++)
				{
					b[a[k]].f=0;
					b[a[k]].id=0;
					ans[a[k]]--;
				}
				b[a[j]].f=1;
			}
			else
			{
				b[a[j]].f=1;
				b[a[j]].id=j;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<' ';
	}
	return 0;
}
