#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
using namespace std;
const int N=1e5+10,maxl=1e3+10;
int c,T,n,k;
signed main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>c>>T;
	for(int op=1;op<=T;op++)
	{
		cin>>n>>k;
		for(int i=1,u,v;i<=n;i++) cin>>u>>v;
		cout<<op<<"\n";
	}
	return 0;
}
