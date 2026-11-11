#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
struct boo{
	bool f;
	int pos;
} box[N];
bool flag[N];
int ans[N];
int u[N];
int a[N];
int n,m;
void init(){for(int i=1;i<=n;i++)box[i].f=0,box[i].pos=0,flag[i]=0;return;}
signed main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int cnt=0;
		init();
		for(int j=i;j<=n;j++)
		{
			if(box[a[j]].f)
			{
				for(int k=box[a[j]].pos;k<=cnt;k++)
				{
					box[u[k]].f=0;
					box[u[k]].pos=0;
					u[k]=0;
				}
				cnt=box[a[j]].pos+1;
				u[cnt]=a[j];
				box[a[j]].f=1;
				box[a[j]].pos=cnt;
			}
			else
			{
				cnt++;
				u[cnt]=a[j];
				box[a[j]].f=1;
				box[a[j]].pos=cnt;
			}
		}
		for(int j=1;j<=cnt+1;j++)
		{
			if(flag[u[j]]==false)
			{
				flag[u[j]]=true;
				ans[u[j]]++;
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[a[i]]<<' ';
	}
	return 0;
}
/*
4 3
1 2 1 3
*/
