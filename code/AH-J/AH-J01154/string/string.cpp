#include <bits/stdc++.h>
using namespace std;
int n;
long ans;
struct{
      long x;
      string s;
	}a[100010];
int main()
{
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    cin>>a[i].x>>a[i].s;
    if(n==1) ans=0;
    else if(n==2)
    {
		if(a[1].s==a[2].s) ans=0;
		else ans=min(a[1].x,a[2].x);
	}
    else
    {
	    int i=1,j=n;
	    while(i<j&&j>i)
	    {
			i++;
			j--;
			if(a[i].x>0&&a[j].x>0)
			{
			    if(a[i].s==a[j].s&&a[i].x!=a[j].x)
			    {
				    int len=max(a[i].x,a[j].x);
				    len-=min(a[i].x,a[j].x);
				    if(a[i].x>a[j].x) a[i].x=len,i-=1;
				    else a[j].x=len,j+=1;
			    }
			    else if(a[i].s!=a[j].s)
			    {
			    	ans+=min(a[i].x,a[j].x);
			    	int len=max(a[i].x,a[j].x);
			    	len-=min(a[i].x,a[j].x);
				    if(a[i].x>a[j].x) a[i].x=len,i-=1;
				    else if(a[i].x<a[j].x)a[j].x=len,j+=1;
			    }
		    }
		    else if(a[i].x>0&&a[j].x==0) i--;
		    else if(a[i].x==0&&a[j].x>0) j++;
	    }
	}
	cout<<ans;
    return 0;
}

