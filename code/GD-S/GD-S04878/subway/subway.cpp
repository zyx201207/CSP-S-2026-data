
#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e3+5;
ll d[N][N];
ll w[N];
ll a[N],t[N];
ll c,n,m,z,q;
void solve(){
	
	for(int i=1;i<=m;i++){
		cin>>w[i];
		memset(d[i],-1,sizeof d[i]);
	}
	for(int i=1;i<=n;i++){
		int l;
		cin>>l;
		for(int j=1;j<=l;j++){
			cin>>a[j]>>t[j];
		}
		for(int j=1;j<l;j++){
			for(int k=j+1;k<=l;k++){
				if(d[a[j]][a[k]]==-1){
					d[a[j]][a[k]]=d[a[k]][a[j]]=t[j]+t[k];
					
				}
				else if(t[j]+t[k]<d[a[j]][a[k]]){
					d[a[j]][a[k]]=d[a[k]][a[j]]=t[j]+t[k];
				}
			}
		}
	}
	for(int i=3;i<=m;i++){
		for(int j=1;j<i;j++){
			for(int k=1;k<i;k++){
				if(k==j) continue;
				else if(d[j][k]!=-1&&d[k][i]!=-1&&(d[j][i]==-1||d[k][i]+d[j][k]<d[j][i])) d[j][i]=d[i][j]=d[k][i]+d[j][k];
			}
		}
		for(int j=1;j<i-1;j++){
			for(int k=j+1;k<=i-1;k++){
				if(d[j][i]!=-1&&d[k][i]!=-1&&(d[k][j]==-1||d[k][i]+d[j][i]<d[j][k])) d[j][k]=d[k][j]=d[k][i]+d[j][i];
			}
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<w[x]+d[x][y]+w[y]<<endl;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>c>>n>>m>>z>>q;
	solve();
}
