#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5,M=3e5+5;
long long n,m,a[N],ans[M],b[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int t=1;t<=n;t++)
	{
		memset(b,0,sizeof(b));
		for(int i=t;i<=n;i++)
		{
			bool tt=0;
			for(int j=t;j<i;j++)
			{
				if(a[j]==a[i] && b[j]==0){
					tt=1;
					b[j]=1;
					b[i]--;
					break;
				}
			}
			if(tt)
				for(int j=t;j<=n;j++)
					b[j]=b[j]+b[j-1];

		}
		for(int j=t;j<=n;j++)
			if(b[j]==0)ans[a[j]]++;
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
	return 0;
}
