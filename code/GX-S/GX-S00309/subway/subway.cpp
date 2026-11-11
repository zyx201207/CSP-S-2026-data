#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
#include<stack>
#include<map>
#include<vector>
using namespace std;

int c,n,m,d,q,w[500001];

unsigned long long li[501][501];
struct line
{
  int k,a[500001];
}s[501];
struct nn
{
  int tot,sum[501];
}mp[500001];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++)
	  scanf("%d",&w[i]);
	for(int i=1;i<=n;i++)
	{
	  scanf("%d",&s[i].k);
	  for(int j=1;j<=s[i].k;j++)
	  {
		int x=0,y=0;
	    scanf("%d %d",&x,&y);
	    s[i].a[x]=y;
	    mp[x].tot++,mp[x].sum[mp[x].tot]=i;
	  }
	}
	memset(li,0x7f,sizeof(li));
	//printf("%llu\n",li[0][0]);
	for(int i=1;i<=m;i++)
	  for(int j=1;j<mp[i].tot;j++)
	    for(int k=j+1;k<=mp[i].tot;k++)
	    {
		  int x=mp[i].sum[j],y=mp[i].sum[k];
		  //cout<<i<<x<<" "<<j<<y<<endl;
	      li[x][y]=li[y][x]=min(li[x][y],(unsigned long long)(s[x].a[i]+s[y].a[i]));
	    }
   // cout<<li[2][3]<<endl;
	for(int i=1;i<=n;i++)
	  for(int j=i+1;j<=n;j++)
	    for(int k=1;k<=n;k++)
	      li[i][j]=li[j][i]=min(li[i][j],li[i][k]+li[k][j]);

    //cout<<li[1][2]<<endl<<li[2][3]<<endl;
	while(q--)
	{
	  int x=0,y=0;
	  unsigned long long ans=2139062143;
	  scanf("%d %d",&x,&y);
	  for(int i=1;i<=mp[x].tot;i++)
	    for(int j=1;j<=mp[y].tot;j++)
	    {
		  int x1=mp[x].sum[i],y1=mp[y].sum[j];
		  if(x1!=y1)
	        ans=min(ans,li[x1][y1]+s[x1].a[x]+s[y1].a[y]);
	      else
	        ans=min(ans,(unsigned long long)(s[x1].a[x]+s[y1].a[y]));
	    }
	  //printf("%d\n",ans);
	  printf("%llu\n",w[x]+w[y]+ans);
	}
	return 0;
}

