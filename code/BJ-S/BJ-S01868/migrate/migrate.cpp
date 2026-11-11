#include<algorithm>
#include<iostream>
#include<fstream>
#include<vector>
using namespace std;
int c,t,n;
#define cin lyc
#define cout lmy
long long d,x[2000005];
ifstream cin("migrate.in");
ofstream cout("migrate.out");
int nxt[2000005][25],lax[2000005][25],laz[2000005][25];
void mian()
{
	cin>>n>>d;
	for(int i=1;i<=n;i++)	cin>>x[i];
	long long ans=0;
	for(int i=1;i<=n;i++)
		nxt[i][0]=upper_bound(x+1,x+n+1,x[i]+d)-x-1,
		lax[i][0]=(nxt[i][0]>i+1?nxt[i][0]-1:0),laz[i][0]=(lax[i][0]>i+1?lax[i][0]-1:0);
	for(int j=1;j<=20;j++)
		for(int i=1;i<=n;i++)
			nxt[i][j]=nxt[nxt[i][j-1]][j-1],
			lax[i][j]=max(nxt[lax[i][j-1]][j-1],lax[nxt[i][j-1]][j-1]),
			laz[i][j]=max({laz[nxt[i][j-1]][j-1],lax[lax[i][j-1]][j-1],nxt[laz[i][j-1]][j-1]});
	for(int i=1;i<=n;i++)
	{
		int a=i,b=i,c=i;
		for(int j=20;j>=0;j--)
		{
			int aa=nxt[a][j];
			int bb=max(nxt[b][j],lax[a][j]);
			int cc=max({lax[b][j],nxt[c][j],laz[a][j]});
			if(aa!=bb)	a=aa,b=bb,c=cc;
		}
		c=max({lax[b][0],nxt[c][0],laz[a][0]});
		b=max(nxt[b][0],lax[a][0]);
		a=nxt[a][0];
		if(a!=b)	continue;
		int left=a+1;
		for(int j=20;j>=0;j--)
		{
			int aa=nxt[a][j];
			int bb=max(nxt[b][j],lax[a][j]);
			int cc=max({lax[b][j],nxt[c][j],laz[a][j]});
			if(bb!=cc)	a=aa,b=bb,c=cc;
		}
		int right=a+1;
		c=max({lax[b][0],nxt[c][0],laz[a][0]});
		b=max(nxt[b][0],lax[a][0]);
		a=nxt[a][0];
		right=a+1;
//		cout<<left<<","<<right<<": "<<i<<endl;
		ans+=max(0,(right-left+1)/2);
	}
	cout<<ans<<endl;
}
int main()
{
	cin>>c>>t;
	while(t--)	mian();
}