#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+1;
ll n,m,a[N],js[N],c[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(ll i=p;i<=n;i++)
		{
			cin>>a[i];
			js[i]+=1;
			if(js[i]>1)
			{
				for(int k=1;k<=i;k++)
				{
					js[k]--;
					c[k]=0;
				}
			}
			c[i]=a[i];
		}
	for(ll p=2;p<=m;p++)
	{
		for(ll i=p;i<=n;i++)
		{
			js[i]+=1;
			if(js[i]>1)
			{
				for(int k=1;k<=i;k++)
				{
					js[k]--;
					c[k]=0;
				}
			}
			c[i]=a[i];
		}
	}
	for(int i=1;i<=n;i++)
	{
		cout<<js[i]<<" ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
