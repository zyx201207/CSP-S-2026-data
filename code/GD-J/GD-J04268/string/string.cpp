#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr int N=2e5+10;
int n,a[N],ans;
char c[N];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	for(int i=1,j=n,rst1=a[1],rst2=a[n];i<j;)
	{
		int minn=min(rst1,rst2);
		if(c[i]!=c[j]) ans+=minn;
		rst1-=minn,rst2-=minn;
		if(rst1==0) i++,rst1=a[i];
		if(rst2==0) j--,rst2=a[j];
	}
	cout<<ans;
}
