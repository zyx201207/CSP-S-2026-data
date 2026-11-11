#include<bits/stdc++.h>
using namespace std;
#define ll long long
int cmp(int a,int b)
{
	return a<b;
}
void solve()
{
	ll n,m;
	scanf("%lld %lld",&n,&m);
	ll ai[n+5],Cyrene=1,res=0,len=0;
	bool f=false;
	scanf("%lld",&ai[i]);
	for(int i=2;i<=n;i++) 
	{
		scanf("%lld",&ai[i]);
		if(ai[i-1]>ai[i]) f=true;
	}
	if(f) sort(ai+1,ai+n+1,cmp);
	for(int i=1,j=2;j<=n;j++)
	{
		res+=(ai[j]-ai[j-1])*(j-i);
		len++;
		if(res>m)
		{
			Cyrene=max(Cyrene,len);
			while(res>m&&i<=j) res-=(ai[j]-ai[i]),len--,i++;
		}
	}
	Cyrene=max(Cyrene,len);
	cout<<Cyrene;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int T=1;
	while(T--) solve();
	return 0;
} 
