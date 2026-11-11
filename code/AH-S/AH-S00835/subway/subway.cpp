#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q,tim=0;
int w[506];
int k[50005];
int a[50005][506],t[50005][506],wei[2000][2000][23];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}
	for(int i=1;i<=m;i++){
		cin>>k[i];
		cin>>a[1][k[i]]>>t[1][k[i]];
		cin>>a[2][k[i]]>>t[2][k[i]];
	}
	while(q--){
		int fr,en;
		cin>>fr>>en;
		tim=0;
		tim+=w[fr];
		tim+=w[en];
		for(int i=fr;i<=en;i++){
			tim+=(w[fr]+a[i][i]);
		}
		cout<<tim;
	}
	return 0;
}

