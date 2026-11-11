#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],s=0;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
    	cin>>a[i];
	}
	sort(a+1,a+1+n);
	int l=1;
	int r=l+1;
	for(int i=2;;i++)
	{
	    int x=0;
		for(int j=l;j<=i;j++)
		{
			x+=a[i]-a[j];
		}
		if(x<=m)
		{
			r++;
		}
		else
		{
			l++;
			r=l+1;
		}
		s=max(s,r-l);
		if(s>=n-l)
		{
			break;
		 } 
	}
	cout<<s;
	return 0;
 } 
