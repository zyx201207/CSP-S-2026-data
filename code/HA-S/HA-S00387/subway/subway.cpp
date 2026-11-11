#include<bits/stdc++.h>
using namespace std;
const int N=505,M=5e5+5;
int dis[M];
int a[205][405];
int main()
{
  freopen("subway.in","r",stdin);
  freopen("subway.out","w",stdout);	
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int c,m,n,d,T;
  cin>>c>>m>>n>>d>>T;
  int i;
  memset(a,-1,sizeof(a));	
  for(i=1;i<=n;i++)
  {
   int i_num,x,t;
   cin>>i_num;
   for(int j=1;j<=i_num;j++)
   {
   	cin>>x>>t;
    a[i][x]=t;
   }	
  }
  queue<int>q;
  while(T--)
  {
   for(i=1;i<=m;i++)
   dis[m]=0x3f;
   int s,t;
   cin>>s>>t;
   dis[s]=0;
   q.push(s);
   while(!q.empty())
   {
   	int d1=q.front();
   	q.pop();
   	int j,l;
   	for(j=1;j<=n;j++)
   	{
   	 if(a[j][d1]!=-1) 
	 {
	  for(l=1;l<=m;l++)
	  if(a[j][l]!=-1)  
	  {
	   if(dis[l]>dis[d1]+a[j][d1]+a[j][l])  
	   {
	    dis[l]=dis[d1]+a[j][d1]+a[j][l];
	    q.push(l);
	   }	
	  }
	 }  
	}
   }	
   cout<<dis[t]<<'\n';
  }
	
return 0;	
}
