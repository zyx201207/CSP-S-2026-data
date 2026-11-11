#include<bits/stdc++.h>
using namespace std;
long long n,m,a[50005],l=0,r=0,b[50005];
map<long long ,long long>d;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
     cin>>a[i];	
	}
	for(int i=1;i<=n;i++)
	{
		long long c[50005];
		l=i;r=i-1;
	 for(int j=i;j<=n;j++)
	 {
	  if(c[a[j]]!=0&&c[a[j]]>=l&&c[a[j]]<=r&&r>0)
	  {
	  	l=r+1;
	  } 
	  
	  r++;
	  c[a[j]]=j;
	 }

	 for(int j=l;j<=r;j++)
     {
      d[a[j]]++;
	 }
	 cout<<endl;
	}
	for(int i=1;i<=m;i++)
	{
	 if(d[i]!=0)cout<<d[i]<<" ";
	 else continue;	
	}

return 0;
}
