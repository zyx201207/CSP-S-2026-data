#include <bits/stdc++.h>
using namespace std;
const int N=5e5+10;
typedef  unsigned long long ull;
int w[N],k[N];
struct node{
	int a,t,pas;
}rt[501][1001];
int solve(int x,int y,int sum){
	for(int i=1;i<=n;++i){
		for(int j=1;j<=k[i];++i){
			if(rt[i][j].a==x){
				
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
	int c,n,m,d,q;cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;++i)cin>>w[i];
	for(int i=1;i<=n;++i){
		cin>>k[i];
		for(int j=1;j<=2*k;++j){
			if(j&1){
				cin>>rt[i][j/2+1].a;
			}
			else cin>>rt[i][j/2].t;
		}
	}
	for(int i=1;i<=q;++i){
		int x,y;cin>>x>>y;
		cout<<solve(x,y,0)<<"\n";
	}
	return 0;
}
