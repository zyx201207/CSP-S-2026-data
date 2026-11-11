#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n;
long long sum,cnt;
long long a[N];
char b[N];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>b[i];
		sum+=a[i];
	}
    for(int i=1,j=n;i<=j;)
    {
    	if(b[i]==b[j])
    	{
    	   if(a[i]<a[j])
    	   {
    	   	  a[j]-=a[i];
    	   	  i++;
		   }
		   else if(a[i]>a[j])
		   {
		   	       a[i]-=a[j];
		   	       j--;
		   }
		   else
		   {
		   	   i++;
		   	   j--;
		   }
		}
		else
		{
			if(a[i]<a[j])
    	    {
    	       cnt+=a[i];
    	   	   a[j]-=a[i];
    	   	   i++;
		    }
		    else if(a[i]>a[j])
		    {
		    	    cnt+=a[j];
		   	        a[i]-=a[j];
		   	        j--;
		    }
		    else
		    {
		    	cnt+=a[i];
		   	    i++;
		   	    j--;
		    }
		}
	}
	cout<<cnt;
	return 0;
}

