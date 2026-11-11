#include<bits/stdc++.h>
using namespace std;
long long a[200005];
char s[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
    int n;
    cin>>n;
    long long ans=0;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i]>>s[i];
    }
    int l=1;
    int r=n;
    while(l<r)
    {
        if(s[l]!=s[r])
        {
        	if(a[l]<a[r])
        	{
        		ans+=a[l];
        		a[r]-=a[l];
        		l++;
        	}
        	else if(a[l]>a[r])
        	{
        		ans+=a[r];
        		a[l]-=a[r];
        		r--;
        	}
        	else 
        	{
        		ans+=a[r];
        		l++;
        		r--;
        	}
        }
        else 
        {
        	if(a[l]<a[r])
        	{
        		a[r]-=a[l];
        		l++;
        	}
        	else if(a[l]>a[r])
        	{
        		a[l]-=a[r];
        		r--;
        	}
        	else 
        	{ 
        		l++;
        		r--;
        	}
        }
    }
    cout<<ans;
	return 0;
}

