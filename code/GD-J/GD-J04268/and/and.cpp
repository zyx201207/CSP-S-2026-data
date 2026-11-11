#include<bits/stdc++.h>
using namespace std;
#define int long long
constexpr int N=2e5+10;
int n,m,a[N],l[N],r[N],ans;
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	r[0]=1,l[n+1]=n;
	for(int i=1;i<=n;i++) cin>>a[i],l[i]=i-1,r[i]=i+1;
	for(int i=30,sum=0;i>=0;i--,sum=0)
	{
		for(int j=r[0];j<=n;j=r[j]) if(a[j]&(1ll<<i)) sum++;
		if(sum>=m)
		{
			ans+=(1<<i);
			for(int j=r[0];j<=n;j=r[j])
				if((a[j]&(1ll<<i))==0)
					r[l[j]]=r[j],l[r[j]]=l[j];
		}
	}
	cout<<ans;
}
