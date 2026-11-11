#include <bits/stdc++.h>
using namespace std;

const int maxn=5e5+10;
int n;
long long m;
long long a[maxn];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i=0;i<n;i++)cin>>a[i];
	sort(a,a+n);
	
    int l,ans=1;
    long long la=0,s;
    for (l=0;l+ans<n;l++)
    {
    	if (l)la-=(a[l+ans]-a[l-1]);
    	int r;
    	bool flag=false;
    	for (r=l+ans;r<n;r++)
    	{
    	    s=a[r]-a[r-1];
    	    la+=s*(r-l);
    	    if (la>m)
    	    {
    	    	flag=true;
    	    	break;
			}
		}
        ans=max(ans,r-l);
	}
	cout<<ans<<"\n";
} 
