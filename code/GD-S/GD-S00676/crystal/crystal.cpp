#include<bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
#define int long long
using namespace std;
const int N=5e5+20;
int n,m,a[N],s[N];
signed main()
{
	freopen("crystal.in","r",stdin);freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	fo(i,1,n)cin>>a[i];
	sort(a+1,a+n+1);
	fo(i,1,n)s[i]=s[i-1]+a[i];
	int j=1,ans=0;
	fo(i,1,n)
	{
		while(a[i]*(i-j+1)-(s[i]-s[j-1])>m)j++;
		ans=max(ans,i-j+1);
	}
	cout<<ans;
	return 0;
}//10min
