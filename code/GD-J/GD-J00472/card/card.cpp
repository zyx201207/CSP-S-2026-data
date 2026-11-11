#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int a[N],wh[N],use[N],ans[N];
int n,m,now=0;
vector<int> before;
signed main()
{
	 freopen("card.in","r",stdin);
	 freopen("card.out","w",stdout);
	 ios::sync_with_stdio;
	 cin.tie(0);
	 cout.tie(0);
	 cin>>n>>m;
	 for(int i=1;i<=n;i++)
	 {
	 	cin>>a[i];
	 }
	 if(n>=500)
	 {
	 	for(int i=1;i<=m;i++)
	 	{
	 		ans[i]=lower_bound(a+1,a+n+1,i+1)-ans-1;
		 }
	 }
	 for(int k=1;k<=n;k++)
	 {
	 	now=0;
	 	memset(wh,0,sizeof(wh));
	 	memset(use,0,sizeof(use));
		 for(int i=k;i<=n;i++)
		 {
		 	if(!wh[a[i]])
		 	{
		 		wh[a[i]]=++now;
		 		use[now]=a[i];
			}
			else 
			{
				for(int j=wh[a[i]]+1;j<=now;j++)
				{
					wh[use[j]]=0;
					use[j]=0;
				}
				now=wh[a[i]];
			}
		}
		 for(int i=1;i<=m;i++)
		 	if(wh[i])
		 		ans[i]++;
	}
	for(int i=1;i<=m;i++)
	{
		cout<<ans[i]<<" ";
	}
	return 0;
}

