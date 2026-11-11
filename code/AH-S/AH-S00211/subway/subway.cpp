#include <iostream>

using namespace std;

const int N=1e5*5+10;
int c,n,m,d,q;
int w[N],k[N],a[1000][1000],t[1000][1000];

int main()
{
  freopen("subway.in","r",stdin);
  freopen("subway.out","w",stdout);
  
  scanf("%d %d %d %d %d",&c,&n,&m,&d,&q);
  for(int i=1;i<=n;i++)scanf(" %d",&w[i]);
  for(int i=1;i<=n;i++)
  {
	  scanf(" %d",&k[i]);
	  for(int j=1;j<=2*k[i];j++)scanf(" %d %d",&a[i][j],&t[i][j]);
  }
  
  while(q--)
  {
	  int ans=0;
	  
	  int x,y;
	  scanf(" %d %d",&x,&y);
	  
	  ans+=w[x]+w[y];
	  
	  
  }
  
  return 0;
}
