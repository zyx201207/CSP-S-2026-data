#include<bits/stdc++.h>
using namespace std;

int a[9]={0,1,10,11,100,101,110,111,1000};
int n,m;
long long b,s[200001],c[200001];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin >> n >> m;
    for(int i=1;i<=n;i++)
    {
      cin >> b;
      int z=b/8,l=b%8;
      if(b>8)
      {
		  s[i]=z*1000+a[l];
      }
      else
        s[i]=a[l];
    }
    if(m==1)
    {
			  int ans=2,zs=0;
			  int t,maxx=-10000;
			  for(int i=1;i<=n;i++)
			    if(maxx<s[i])  maxx=s[i];
			  t=maxx;
			  while(t)
			  {
				  int q=t%10;
				  for(int i=1;i<=zs;i++)
				  {
				    ans+=q*2;
				    cout << ans << endl;
				  }
				  t/=10;
				  zs++;
			  }
			  cout << ans;
    }
    if(m==2)
    {
		int jsq=1;
	    	for(int i=1;i<=n;i++)
	    	  for(int j=i++;j<=n;j++)
	    	  {
				  int t=s[i],o=s[j],sp=0;
				  if(t<o)  swap(t,o);
			      while(t)
			      {
			    	  int q=t%10,w=o%10,y;
			    	  if(q!=w)  y=0;
			    	  else y=1;
			    	  sp=sp*10+y;
			    	  t=t/10;
			    	  o=o/10;
				  }
				  c[jsq]=sp;
				  jsq++;
			  }
		    int ans=2,zs=0;
			  int t,maxx=-10000;
			  for(int i=1;i<=n;i++)
			    if(maxx<c[i])  maxx=c[i];
			  t=maxx;
			  while(t)
			  {
				  int q=t%10;
				  for(int i=1;i<=zs;i++)
				  {
				    ans+=q*2;
				    cout << ans << endl;
				  }
				  t/=10;
				  zs++;
			  }
			  cout << ans;
    }
    return 0;	
}
