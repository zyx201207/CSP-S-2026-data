#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
void fre()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
}
int n,m;
const int MAXN=5e5+10;
int a[MAXN],tmp[MAXN],tong[MAXN],vis[MAXN];
map<int,int>mp;
int main()
{
	fre();
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		int tot=0;
		for(int j=1;j<=n;j++)vis[a[j]]=0;
		for(int j=i;j<=n;j++)
		{
			if(vis[a[j]]==0)
			{
				tmp[++tot]=a[j];
				vis[a[j]]=tot;
			}
			else {
				//if(i==6)cout<<a[j]<<" ! "<<vis[a[j]]<<" "<<tot<<;
				while(tmp[tot]!=a[j]&&tot>0)
				{
					vis[tmp[tot]]=0;
					tot--;
				}
				tmp[tot]=a[j];
				vis[a[j]]=tot;
			}
		}
		for(int j=1;j<=tot;j++)
		{
			//cout<<tmp[j]<<" ";
			tong[tmp[j]]++;
		}
		//cout<<endl;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<tong[i]<<" ";
	}
	return 0;
}

