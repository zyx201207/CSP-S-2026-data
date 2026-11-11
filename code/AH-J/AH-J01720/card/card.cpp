#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],t[500005],lst=0,ans[300005];
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
	}
	bool vis[500005];
	for(int i=1;i<=n;i++)
	{
//		cout<<"?";
		memset(vis,0,sizeof(vis));
		memset(t,0,sizeof(t));
		lst=0;
		for(int j=i;j<=n;j++)
		{
////			cout<<"i "<<i<<" j "<<j<<"\n";
//			for(int k=1;k<=lst;k++)
//			{
//				cout<<t[k]<<" ";
////				ans[t[j]]++;
//			}
//			cout<<"\n";
//			if(vis[a[j]]==0)
//			{
//				t[++lst]=a[j];
//				vis[a[j]]=1;
//			}
//			else
//			{
//				vis[a[j]]=1;
				bool f=0;
				for(int k=lst;k>=1;k--)
				{
					if(t[k]==a[j])
					{
						lst=k;
						f=1;
						break;
					}
				}
				if(f==0)
				{
					t[++lst]=a[j];
				}
//			}
		}
//		cout<<"*&&***\n";
		for(int j=1;j<=lst;j++)
		{
//			cout<<t[j]<<" ";
			ans[t[j]]++;
		}
//		cout<<"\n";
	} 
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
    return 0;
}
