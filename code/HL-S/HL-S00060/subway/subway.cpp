#include<bits/stdc++.h>
using namespace std;
const int N=505;
const int M=5e5+10;
int a[N][N],t[N][N],ww[N][N],ww2[N];
int w[M],k[M];
int c,n,m,d,q;
int num=0,maxnum=0,xx,yy;
void dfs(int xx2,int num)
{
  if(xx2==yy) 
  {
    maxnum=num;
    return ;
  }
  for(int i=1;i<=k[xx2];i++)
  {
    num=num+a[xx2][i];
    if(ww2[a[xx2][i]]!=1)
    {
      for(int j=1;j<=ww2[a[xx2][i]];j++)
	  {
	   if(ww[a[xx2][i]][j]!=xx2)
	   {
	     dfs(ww[a[xx2][i]][j],num);
	   }
	  }
	  num=num-a[xx2][i];
	}
  }
}
int main()
{
  freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
  scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
  for(int i=1;i<=m;i++) scanf("%d",&w[i]);
  for(int i=1;i<=n;i++) 
  {
    scanf("%d",&k[i]);
    for(int j=1;j<=k[i];j++)
    {
      scanf("%d%d",&a[i][j],&t[i][j]);
      ww[a[i][j]][++ww2[a[i][j]]]=i;
	}
  }
  num=0,maxnum=0;
  //cout<<"UIHFOSFHGOIHFGIOWEHRG0"<<q;
  for(int i=1;i<=q;i++)
  { 
    scanf("%d%d",&xx,&yy);
    dfs(xx,num);
    printf("%d\n",maxnum);
  }
  return 0;
}