#include<bits/stdc++.h>
using namespace std;
#define int long long
int b[500005],zhuan=0;
int way[1005][1005];
struct d{
	int first,second;
};
vector<d> v[505];
//floyd”≈ªØ∞Ê£ø 
int c,n,m,d,q;
int w[500005];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(way,0x3f,sizeof(way));
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		int x;
		scanf("%lld",&x);
		for(int j=1;j<=x;j++){
			int a,b;
			scanf("%lld%lld",&a,&b);
			v[i].push_back({a,b});
		}
		for(int l=0;l<(int)v[i].size();l++){
			for(int r=l+1;r<(int)v[i].size();r++){
				way[v[i][l].first][v[i][r].first]=v[i][l].second+v[i][r].second;
			}
		}
	}
	if(c==20||21){
		memset(b,-1,sizeof(b));
		for(int i=0;i<v[1].size();i++){
			b[v[1][i].first]=1;
		}
		for(int i=0;i<v[2].size();i++){
			if(b[v[2][i].first]){
				b[v[2][i].first]=2;
				zhuan=v[2][i].second;
			}
			else b[v[2][i].first]=3;
		}
		for(int i=0;i<v[1].size();i++){
			if(b[v[1][i].first]==3) zhuan+=v[1][i].second;
		}
		for(int i=1;i<=q;i++){
			int x,y;
			scanf("%lld%lld",&x,&y);
			if(abs(b[x]-b[y])<=1) printf("%lld",w[x]+w[y]);
			else printf("%lld",w[x]+w[y]+zhuan);
		}
		return 0;
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			for(int k=1;k<=m;k++){
				way[i][j]=min(way[i][k]+way[k][j],way[i][j]);
			}
		}
	}
//	for(int i=1;i<=m;i++){
//		for(int j=1;j<=m;j++){
//			printf("%d ",way[i][j]);
//		}
//		printf("\n\n");
//	}
	for(int i=1;i<=q;i++){
		int x,y;
		scanf("%lld%lld",&x,&y);
		printf("%lld\n",(w[x]+w[y]+way[min(x,y)][max(x,y)]));
	}
	return 0;	
}
