#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll read(){ll x;scanf("%lld",&x);return x;}
const int N=2e5+10;
//void hyw(){puts("hyw");}
ll a[N];
int n,m;
bool xy1(ll x,ll y){return x>y;}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i) a[i]=read();
	sort(a+1,a+1+n,xy1);
	cout<<a[m];
	return 0;
}
/*
这题真的这么简单吗？？？？
不对劲吧 
*/
