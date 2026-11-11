#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ans=0,qw=0,b; 
bitset<200005> a[45],c,d;
signed main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>b;
		qw=0;
		while(b>0){if(b%2==1) a[qw][i]=1;b/=2,qw++;}
	}
	for(int i=0;i<=200001;i++) c[i]=1;
	for(int i=43;i>=0;i--)
	{
		d=c&a[i];
		if(d.count()>=m) ans+=1<<i,c=d;
	}
	cout<<ans;
	return 0;
}
