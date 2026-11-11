#include <bits/stdc++.h>
#define ll long long
using namespace std;
int c,n,m,d,q,w[500005],s[20005][20005],num,a[5005][5005],b[5005],k[5005];

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	for(int i=1;i<=n;i++) //i表示几号线 
	{
		int x,t;
		cin>>x;
		for(int j=1;j<=x;j++)
		{
			cin>>num>>t;
			a[i][num]=t;
		}
	}
	while(q--)
	{
		int x,y,now1=0,now2=0,ans=0;
		cin>>x>>y;
		for(int i=1;i<=n;i++)
		{
			if(a[i][x]!=0)
				b[++now1]=i;
			if(a[i][y]!=0)
				k[++now2]=i;
		}
		for(int i=1;i<=now1;i++)
			for(int j=1;j<=now2;j++)
				if(b[i]==k[j])
					ans=a[b[i]][x]+a[k[j]][y];
		if(ans==0)
		{
			for(int i=1;i<=now1;i++)
				for(int j=1;j<=300;j++)
				if(a[b[i]][j]!=0)
					for(int l=1;l<=n;l++)
						if(a[l][j]!=0&&a[l][y]!=0)
							ans=a[l][j]+a[l][y]+a[b[i]][x];
		}cout<<w[x]+w[y]+ans<<"\n";
	}
	return 0;
} 

