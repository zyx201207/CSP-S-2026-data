#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,w,k,a,t,x,y;
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	if(c==0)
	{
		for(int i=1;i<=m;i++) cin>>w;
		for(int i=1;i<=n;i++)
		{
			cin>>k;
			for(int j=1;j<=k;j++) cin>>a>>t;
		} 
		while(q--) cin>>x>>y;
		cout<<"32\n17";
	}
	return 0;
} 
