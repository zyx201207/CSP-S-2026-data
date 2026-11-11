#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10,M=550;
int w[M];
vector<int,pair<int,int>> e[M];
int a[N],t[M][M];
bool st[M];
int main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);	
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a[i][j];
			cin>>t[i][a[i][j]];
		}
	} 
	while(q--){
		int s,e;
		cin>>s>>e;
		int ans=w[s]+w[e];
		cout<<ans<<"\n";
	} 
	return 0;
}
