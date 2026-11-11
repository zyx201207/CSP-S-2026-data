#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
long long a[N],t[N];
char c[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	long long n,i,j,l,r,ans=0,L,R;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
		t[i]=t[i-1]+a[i];
	}
	for(i=1;i<=n;i++)
	{
		l=t[n]+1-t[i];
		r=t[n]-t[i-1];
		L=lower_bound(t+1,t+n+1,l)-t;
		R=lower_bound(t+1,t+n+1,r)-t;
		for(j=L;j<=R;j++)
			if(c[j]!=c[i])
				ans+=min(t[j],r)-max(t[j-1],l-1);
	}
	cout<<ans/2;
	return 0;
}
