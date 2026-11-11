#include<bits/stdc++.h>
using namespace std;
int a[100001];
int p[10001];
int b[100001];
int w[10001];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i];
	}
	if(n==1)
	{
	int k;
	cin>>k;
	int time=0;
     for(int i=1;i<=k;i++)
	 {
	 	cin>>b[i]>>w[i];	 	
	  }
	  for(int j=1;j<=q;j++)
	  {
	  	int x,y;
	  	cin>>x>>y;
	  p[x]=x;
	  p[y]=y; 
	  }
	  for(int i=1;i<=k;i++)
	  {
	  	if(b[i]==p[i])
	  	{
	  		time=time+a[i]+w[i];
		}
	  }
	  cout<<time;
    }
    return 0;
}
