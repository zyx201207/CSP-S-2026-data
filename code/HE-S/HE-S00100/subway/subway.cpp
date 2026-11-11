#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=5e5+50;

int c,n,m,d,q;
int w[N],k[505];

struct node{ int a,t;}s[505];

int32_t main(){
	
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++) cin>>s[i].a>>s[i].t;
	}
	while(q--){
		int x,y,ans=0;
		cin>>x>>y;
		ans=(y-x+1)*2*s[1].t;
		cout<<ans<<'\n';
	}
	return 0;
}

/*

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

*/
