#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=2e6+5;
int n; ll d; ll Tmp[maxn];
ll x[maxn],f1[maxn],f2[maxn];
inline void solve()
{
	scanf("%d%lld",&n,&d);
	for(int i=1;i<=n;i++) scanf("%lld",&x[i]);
	f1[1]=1;
	for(int i=2,j=1;i<=n;i++)
	{
		f1[i]=1;
		while(x[i]-x[j]>d) j++;
		while(j<i&&x[i]-x[j]<=d&&x[i+1]-x[j]>d)
		{
			f1[i]+=f1[j];
			j++;
		}
	}
	f2[n]=1;
	for(int i=n-1,j=n;i>=1;i--)
	{
		f2[i]=1;
		while(x[j]-x[i]>d) j--;
		while(j>i&&x[j]-x[i]<=d&&x[j]-x[i-1]>d)
		{
			f2[i]+=f2[j];
			j--;
		}
	}
	ll ans=0;
	int lu=1,ru=0;
//	for(int i=1;i<=n;i++) cout<<x[i]<<" ";
//	cout<<"\n";
	for(int i=2;i<n-1;i++)
	{
		while(ru+1<=n&&x[ru+1]<x[i+2]-d) ru++;
		while(x[i+1]-d>x[lu]) lu++;
		if(lu<=ru&&ru<i) Tmp[i]=f1[lu]+ru-lu;
		else Tmp[i]=0;
//		cout<<lu<<" "<<ru<<" "<<i<<"\n";
//		cout<<Tmp[i]<<" ";
	}
	int lv=1,rv=0;
	for(int i=2;i<n-1;i++)
	{
		while(rv+1<=n&&x[rv+1]<=x[i]+d) rv++;
		while(x[i-1]+d>=x[lv]) lv++;
		if(i<lv&&lv<=rv) ans+=((ll)Tmp[i])*((ll)rv-lv+f2[rv]);
//		cout<<lv<<" "<<rv<<" "<<rv-lv+f2[rv]<<" AA\n";
	}
	printf("%lld\n",ans);
	return;
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int T; cin>>T>>T; while(T--) solve();
	return 0;
}
