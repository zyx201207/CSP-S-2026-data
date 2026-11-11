#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;
int cmp(int a,int b)
{
	return a>b;
}
void solve()
{
	int n,m,ai[N];
	ll Cyrene;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>ai[i];
	}
	sort(ai+1,ai+n+1,cmp);
	Cyrene=ai[1];
	for(int i=2;i<=m;i++) Cyrene&=ai[i];
	cout<<Cyrene;
}
int main()
{
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int T=1;
	while(T--) solve();
	return 0;	
} 
