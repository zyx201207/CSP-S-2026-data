#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
void solve()
{
	int n,k,u[N],v[N],cnt=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>u[i]>>v[i];
	}
	cout<<u[1]<<'\n';
}
//why? zhe tai dian nao zhong wen shu ru fa shi huai de?
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int C,T;
	cin>>C>>T;
	while(T--){
		solve();
	}
	return 0;
}
