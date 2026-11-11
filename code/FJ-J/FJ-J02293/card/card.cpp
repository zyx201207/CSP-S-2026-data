#include<bits/stdc++.h>
#define fo(i,a,b) for(int i=a;i<=b;++i)
#define of(i,a,b) for(int i=a;i>=b;--i)
#define ll long long
#define N 210510
using namespace std;
int n,m,a[N],ans[N/2];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	fo(i,1,n) 
	{
		cin>>a[i];
		++ans[a[i]];
	}
	fo(i,1,m) ans[i]+=ans[i-1];
	fo(i,1,m) cout<<ans[i]<<' ';
	return 0;
}
