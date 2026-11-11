#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
struct node{
	long long a,t;
};
long long w[500010];
int h[500010];
int k;
int zhan_i[500010];
node zhan[500010][25];
long long f[505][505];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(f,0x3f,sizeof(f));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		int vt;
		cin>>vt;
		for(int j=1;j<=vt;j++){
			int a,t;
			cin>>a>>t;
			zhan[a][zhan_i[a]]={i,t};
			zhan_i[a]++;
//			cout<<zhan_i[a]<<endl;
			if(zhan_i[a]==2){
				k++;
				h[k]=a;
			}
		}
	}
	for(int i=1;i<=k;i++){
		int p=h[i];
//		cout<<1;
		for(int j=0;j<zhan_i[p];j++){
			for(int k=0;k<zhan_i[p];k++){
				if(j!=k){
					f[zhan[p][j].a][zhan[p][k].a]=min(zhan[p][j].t+zhan[p][k].t,f[zhan[p][j].a][zhan[p][k].a]);
//					cout<<f[zhan[p][j].a][zhan[p][k].a]<<" "<<zhan[p][j].a<<" "<<zhan[p][k].a<<endl;
				}
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j){
					f[i][j]=0;
				}
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
			}
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		long long ans=0x3f3f3f3f;
		for(int j=0;j<zhan_i[x];j++){
			for(int k=0;k<zhan_i[y];k++){
				cout<<zhan[x][j].a<<" "<<zhan[x][k].a<<endl;
				ans=min(ans,f[zhan[x][j].a][zhan[x][k].a]);
			}
		}
		cout<<ans+w[x]+w[y]<<endl;
	}
	return 0;
}
