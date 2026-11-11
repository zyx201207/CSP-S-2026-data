#include<bits/stdc++.h>
using namespace std;
int n,m,x,nxt[200005];
bool a[200005][32];
long long k;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	nxt[0]=1;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		nxt[i]=i+1;
		int j=0;
		while(x>0)
		{
			if(x%2==1) a[i][j]=1;
			x>>=1;
			j++;
		}
	}
	for(int i=30;i>=0;i--)
	{
		int l=0;
		for(int j=0;j<=n;j=nxt[j])
		{
			if(a[j][i]==1) l++;
		}
		if(l>=m) 
		{
			int t=0;
			for(int j=nxt[0];j<=n;j=nxt[j])
			{
				if(a[j][i]==1) 
				{
					nxt[t]=j;
					t=j;
				}
			}
			k+=pow(2,i);
		}
	}
	cout<<k;
	return 0;
}

