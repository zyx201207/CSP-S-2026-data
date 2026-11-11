#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const int maxn=5e5+1;
ll a;
ll w[501];
ll f[501][501];
ll oi[501];
int c,n,m,d,q;
void floyd(){
    for(int i=1;i<=m;i++){
     	for(int j=1;j<=m;j++){
     		for(int k=1;k<=m;k++){
     			f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int k,a,t;
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			f[i][j]=INT_MAX;
			if(i==j)f[i][j]=0;
		}
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>a;
			cin>>t;
			if(j!=a){
				f[i][j]=t;
			}else{
				oi[i]=t;
			}
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			if(j!=i)f[j][i]+=oi[i];
		}
	}
	floyd();
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<f[x][y]+w[x]+oi[x]+w[y]-oi[y]<<endl;
	}
	return 0;
} 
