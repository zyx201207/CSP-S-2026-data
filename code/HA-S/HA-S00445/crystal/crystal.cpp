#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+10;
ll read(){ll x;scanf("%lld",&x);return x;}
//void hyw(){puts("hyw");} 
ll n,m; 
ll warma[N],c;
bool f=1;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		warma[i]=read();
		if(i>1&&warma[i-1]!=warma[i]) f=0;}
	if(f)
	{
		cout<<n<<'\n';
		return 0;}
	sort(warma+1,warma+1+n);
	c=warma[2]-warma[1];
	ll ans=m/c;
	ans=(ans>n)?n:ans;
	cout<<ans;
	return 0;
}

