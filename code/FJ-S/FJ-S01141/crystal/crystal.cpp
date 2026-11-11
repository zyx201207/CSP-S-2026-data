#include<bits/stdc++.h>
using namespace std;
const int N=5e5+100,inf=0x3f3f3f3f,MOD=1e9+7;
typedef long long ll;
typedef unsigned long long ull;
ll a[N],s[N];
bool cmp(ll i,ll j) {return i>j;}
int ck(int l,int r) {return a[l]*(r-l+1)-(s[r]-s[l-1]);}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;ll m;scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n,cmp);int r=1,e=1;
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++)
	{
		r=max(r,i);
		while(r<n && ck(i,r+1)<=m) r++;
		e=max(e,r-i+1);
//		cout<<i<<" "<<r<<endl;
	}
	printf("%d\n",e);
	return 0;
}
//100+100+40+25=265
