#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int c,n,m,d,q;
int w[maxn],x[maxn],y[maxn],ans=0;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	string kk[n];int k[n][2000];
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++) getline(cin,kk[i]);
	for(int i=1;i<=q;i++) cin>>x[i]>>y[i];
	for(int i=1;i<=n;i++){
		for(int j=0;j<kk[i].size();j++){
			k[i][j+1]=kk[i][j]-'0';
		}}
	for(int i=1;i<=q;i++){
		ans=0;ans+=w[x[i]];
		
	}
	return 0;
}
