#include<bits/stdc++.h>
typedef long long ll;
const int maxn=2e6;
using namespace std;

ll n,d;
ll a[maxn+65],ans;
int ind[maxn+5];
vector<int>g[maxn+5];
void solve()
{
	ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;++i)cin>>a[i];
	bool flag=1;
	for(int i=2;i<=n;++i)if(a[i]-a[i-1]!=a[2]-a[1])flag=0;
	if(a[n]-a[1]<=d)
	{
		cout<<"0\n";
		return;
	}
	if(flag==0)
	{
		cout<<"0\n";
	}
	cout<<"0\n";
}
int main()
{
	freopen("migrate.out","w",stdout);
	freopen("migrate.in","r",stdin);
	cin.tie(0),cout.tie(0);
	ios::sync_with_stdio(0);
	int cc,_=1;
	cin>>cc>>_;
//	cout<<cc<<" "<<_<<"\n";
	while(_--)solve();
	return 0;
}
/*

0 2
4 2
1 2 3 4
5 2
1 2 3 4 5



*/

