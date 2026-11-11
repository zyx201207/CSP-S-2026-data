#include <bits/stdc++.h>
using namespace std;
const int mx=5e5+10;
int n,ans,l,man;
long long as,m,a[mx];
int cmp(int x,int y)
{
    return x>y;	
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	sort(a,a+n,cmp);
	for(int i=0;i<n;i++)
	{
	    ans++;
	    as+=a[i];
	    while(a[l]*ans-as>m)
	    {
			as-=a[l];
			l++;
			ans--;
	    }
	    man=max(man,ans);
    }
    cout<<man;
    return 0;
}
