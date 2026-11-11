#include<bits/stdc++.h>
using namespace std;
int v[2000006],u[2000006],maxn=-1e9,p,ans,cnt[2000005],maxn2=-1e9,n,k,o;

int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i = 1;i<=t;i++)
	{
		cin>>n>>k;
		for(int j = 1;j<=n-1;j++)
		{
			cin>>v[j]>>u[j];
			
		}
	}
	for(int i = 1;i<=t;i++)
	{
		for(int j = 1;j<=n-1;j++)
		{
			ans=abs(v[j]-u[j]);
			if(ans>maxn)
			{
				maxn=ans;
				cnt[j]++;
			}
			if(cnt[j]>maxn2)
			{

				maxn2=cnt[j];
				p=ans;		
			}
		}
	}
	for(int i = 1;i<=t;i++)
	{
		cout<<p<<endl;
		p++;
	}

	
	return 0;
}
