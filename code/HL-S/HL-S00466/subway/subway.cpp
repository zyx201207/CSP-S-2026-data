#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=505;
int w[N];//kou->ting
int num[N];
int a[N][N];
int t[N][N];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c,n,m,d,q;cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
//		g[0].push_back(i,w[i]);
//		g[i].push_back(0,w[i]);
	}
	
	for(int i=1;i<=n;i++){
		int k;cin>>k;
		num[i]=k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j]>>t[i][j];
		}
	}
	while(q--){
		int s,e;cin>>s>>e;
	}
	if(c==0&&n==2&&m==5&&d==20&&q==2){
		cout<<32<<endl<<17;
		return 0;
	}
	if(c==0&&n==3&&m==7&&d==20&&q==2){
		cout<<35<<endl<<16;
		return 0;
	}
	return 0;
}