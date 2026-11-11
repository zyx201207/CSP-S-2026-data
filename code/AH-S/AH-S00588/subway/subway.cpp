#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string ikun="woshixiaohezi";//I'm true ikun
const int maxn=1e6+10;
ll c,n,m,d,q,f[3001][3001],a[maxn],t[3001][3001],x[maxn],v[3001][3001];
void empt(){
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			f[i][j]=1e9;
			t[i][j]=v[i][j]=0;
		}
	}
	return ;
}
void solve(){
	cin>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>a[i];
	empt();
	for(int i=1;i<=n;i++){
		ll k;
		cin>>k;
		for(int j=1;j<=k;j++)cin>>x[j]>>t[i][x[j]];
		for(int j=1;j<=k-1;j++){
			f[x[j]][x[j+1]]=f[x[j+1]][x[j]]=t[i][x[j]]+t[i][x[j+1]];
			v[x[j]][x[j+1]]=v[x[j+1]][x[j]]=i;
		}
		f[x[1]][x[k]]=f[x[k]][x[1]]=t[i][x[k]]+t[i][x[1]];
		v[x[1]][x[k]]=v[x[k]][x[1]]=i;
	}
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				if(f[i][j]<1e9)continue;
				if(v[i][k]!=v[k][j]){
					f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
				}else{
					f[i][j]=min(f[i][j],f[i][k]+f[k][j]-t[v[i][k]][k]);
				}
			}
		}
	}
	while(q--){
		ll h,g;
		cin>>h>>g;
		cout<<f[h][g]+a[h]+a[g]<<endl;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	while(cin>>c)solve();
    return 0;
}
