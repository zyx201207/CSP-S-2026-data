#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5*2+10;
int n;
int a[N];
char c[N];
int l,r;
ll ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	l=1,r=n;
	while(l<r)
	{
		int s=min(a[l],a[r]);
		a[l]-=s,a[r]-=s;
		if(c[l]!=c[r])
		{
			ans+=s;
		}
		if(a[l]==0) l++;
		if(a[r]==0) r--;
	}
	cout<<ans;
	return 0;
}
