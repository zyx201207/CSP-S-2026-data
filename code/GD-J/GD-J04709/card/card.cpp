#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int n,m,a[N],f[N],le[N],ans,sum,s;
bool v[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>n>>m;
	int nn=n;
	for(int i=1;i<=n;i++)
	  cin>>a[i];
    while(nn!=0)
    {
    	nn--;
    	int p=a[1];
    	le[p]++;
    	for(int i=1;i<nn;i++)
    	  a[i]=a[i+1];
    	for(int i=1;i<=s;i++)
    	  if(f[i]==p)
    	    memset(f,0,sizeof(f)),s=0,f[++s]=p;
    	  else
    	  {
    	  	for(int j=1;j<=s;j++)
    	  	  le[j]++;
		  }
	}
	for(int i=1;i<=m;i++)
	  cout<<le[i]<<" ";
	return 0;
}
