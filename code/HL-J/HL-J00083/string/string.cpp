#include <bits/stdc++.h>
using namespace std;
int n,a[200005],ans=0;
char c;
string s;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	if(n==1)
	{
	    for(int i=0;i<n;i++)
	    {
		    cin>>a[i]>>c;
	    }	
	    ans=0;
	}
	else if(n==2)
	{
        for(int i=0;i<n;i++)
	    {
		    cin>>a[i]>>c;
		    s+=c;
	    }
		if(s[0]!=s[1])
		{
			ans=min(a[0],a[1]);
		}	
	}
	else
	{
		for(int i=0;i<n;i++)
	    {
		    cin>>a[i]>>c;
		    s+=c;
	    }
	    int l=0,r=n-1;
	    while(l<r)
	    {
	    	if(s[l]!=s[r])
	    	{
	    		ans++;
			}
			l++;
			r--;
		}
	}
	cout<<ans<<'\n';
	return 0;
}