#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pii pair<ll,ll>  
const int N=5e5+10,M=550;
ll _,n,m,max_d,q,w[N],len,x,y,t,d[M][M],ans;
vector<pii>line[N];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>_>>n>>m>>max_d>>q;
	for(int i=1;i<=m;i++){
		scanf("%lld",&w[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%lld",&len);
		for(int j=1;j<=len;j++){
			scanf("%lld%lld",&x,&t);
			line[x].push_back({i,t});
		}
	}
	memset(d,0x3f,sizeof(d));
	for(int i=1;i<=n;i++)d[i][i]=0;
	for(int i=1;i<=m;i++){
		for(auto p1:line[i]){
			ll pos=p1.first,t1=p1.second;
			for(auto p2:line[i]){
				ll to=p2.first,t2=p2.second;
				if(pos==to)continue;
				d[pos][to]=min(d[pos][to],t1+t2);
			}
		}
	}
	for(int k=1;k<=n;k++){//floyd
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(d[i][k]<1e18&&d[k][j]<1e18){
					d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
				}
			}
		}
	}
	for(int i=1;i<=q;i++){
		scanf("%lld%lld",&x,&y);
		ans=1e18;
		for(auto p1:line[x]){
			ll pos=p1.first,t1=p1.second;
			for(auto p2:line[y]){
				ll to=p2.first,t2=p2.second;
				ans=min(ans,d[pos][to]+t1+t2);
			}
		}
		printf("%lld\n",ans+w[x]+w[y]);
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
