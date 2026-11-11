#include<bits/stdc++.h>
using namespace std;
int c[5005];
int ans[5005];
int dis[5005];
bool flag[5005][5005];
int main()
{  freopen("card.in","r",stdin);
   freopen("card.out","w",stdout);
   int n,t=0,ti=0,m,sum,j=0;
   int pos;
   cin>>n>>m;
   for(int i=1;i<=n;i++)
   {  	
   	  t++;
   	 cin>>c[i];
   }
   for(int i=1;i<=n;i++)
   { bool vis[5005]={0};
     int ma[5005]={0};
     int pos=0;
   	  sum=i-1;
   	  int e=0;
   	  while(sum<t)
   	  {
   	  	sum++;
   	  	pos++;
   	  	  if(vis[c[sum]==1])
   	  	  {
   	  	  	   for(int x=dis[c[sum]];x<pos;x++)
   	  	  	   {
   	  	  	   	   ma[x]=0;
   	  	  	   	   vis[ma[x]]=0;
   	  	  	   	   dis[ma[x]]=0;
   	  	  	   	   e++;
			   }
			   pos-=e;
			   e=0;
		  }
		  ma[pos]=c[sum];
		  vis[c[sum]]=1;
		  dis[c[sum]]=pos;
	  }
	  for(int x=1;x<=pos;x++)
	  {
	  	for(int b=1;b<=m;b++)
	  	{
	  	 if(ma[x]==b&&!flag[x][b])
	  	 {
	  	 	ans[b]++;
	  	 	flag[x][b]=1;
		 }	
		 flag[x][b]=0;
		}
	  }
   }
   for(int i=1;i<=m;i++)
   {
   	  cout<<ans[i]<<" ";
   }
return 0;
}

