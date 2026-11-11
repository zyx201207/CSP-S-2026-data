#include <bits/stdc++.h>
#define int long long
#define For(i,n) for(int i=1;i<=n;i++)
#define Fors(i,l,r) for(int i=l;i<=r;i++)
using namespace std;
const int N=262144;

int n,a[N],ans;
char c[N];

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
	For(i,n) cin>>a[i]>>c[i];
	
	int l=1,r=n,nl=a[1],nr=a[n];
	while(l<r)
	{
		if(c[l]!=c[r]) ans+=min(nl,nr);
		if(nl>nr)
		{
			nl-=nr;
			r--;
			nr=a[r];
		}
		else if(nl==nr)
		{
			l++;
			r--;
			nl=a[l];
			nr=a[r];
		}
		else
		{
			nr-=nl;
			l++;
			nl=a[l];
		}
	}
	
	cout<<ans;
	
	return 0;
}
