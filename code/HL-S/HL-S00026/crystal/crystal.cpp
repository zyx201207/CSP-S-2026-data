#include<bits/stdc++.h>
using namespace std;
long long a[500005],b[500005],c[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,s=0;
	cin>>n>>m;
	for(long long i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
    for(long long i=n;i>1;i--)
    {
    	b[i]=a[i]-a[i-1];
    	if(i<n)
    	{
    		if(b[i]<b[i+1]) 
    		{
    			c[i]=a[i];
    			a[i]=a[i+1];
    			a[i+1]=a[i];
			}
		}
	}
   for(long long i=1;i<=n;i++)
  {
   	if(m>=b[i]) 
    	{
    	 m=m-b[i];
    	 s++;
		}
		else break;
	}
     cout<<s;
	return 0;
}