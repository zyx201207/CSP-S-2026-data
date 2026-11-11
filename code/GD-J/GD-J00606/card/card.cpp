#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
long long a[N],n,m,w[N],v[N],ans[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++) a[n+1]=a[i];
	for(int i=1;i<=n;i++) 
	{
		memset(v,0,sizeof v);
		memset(w,0,sizeof w);
		for(int j=i;j<=i+n;j++)
		{
			bool flag=1;
			
			for(int k=i;k<=j;k++)
			{
				if(a[k]==a[j]&&!v[k])
				{
					for(int t=k;t<=j;t++) if(!v[t]) w[a[t]]--,v[t]=1;
					flag=0;
					break;
				} 
			}
			if(flag) w[a[j]++]; 
		}
		for(int j=1;j<=m;j++) ans[j]+=max(0,int (w[j]));
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' '; 
} 
