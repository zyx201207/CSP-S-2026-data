#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int maxn=5e5+5; 
ll n,m,a[maxn],lis[maxn],ans[maxn];

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	for(int x=1;x<=n;x++)
	{
		for(int i=1;i<=n;i++) lis[i]=0;
		for(int i=x;i<=n;i++) lis[i]=a[i];
		int pos=x;
		while(pos<=n)
		{
			for(int j=n;j>=pos+1;j--)
			{
				if(a[j]==a[pos]) 
				{
					for(int k=pos;k<=j-1;k++)
						lis[k]=0;
					pos=j;
				} 
			}
			pos++;
		}
		for(int i=1;i<=n;i++)
		{
			ans[lis[i]]++;
		}
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	
	return 0;
}
//Trick||Treat!
