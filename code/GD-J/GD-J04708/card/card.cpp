#include<iostream>
#include<cstring>
using namespace std;
const int N=5e5+10;
int n,m;
int a[N];
int ans[N];
int d[N];
struct node{
	int pre,nxt,vi;
};
node l[N];
bool v[N];
int c=0;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		memset(v,0,sizeof(v));
		for(int j=i;j<=n;j++)
		{
			for(int k=j-1;k>=i;k--)
				if(v[k]==0&&a[k]==a[j])
				{
					for(int t=k;t<j;t++)
						v[t]=1;
					break;
				}
		}
		bool t[N];
		memset(t,0,sizeof(t));
		for(int j=i;j<=n;j++)
			if(v[j]==0&&t[a[j]]==0)
			{
					ans[a[j]]++;
					t[a[j]]=1;
			}
			
//		cout<<'\n';
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<' ';
}
