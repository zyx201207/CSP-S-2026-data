#include<bits/stdc++.h>
#define int long long
#define PII pair<int,int>
#define f first
#define s second
using namespace std;
const int N=550,M=5e5+500,inf=1e18;
int n,m,q,w[M],g[N][N],k[N];
vector<PII>t[M];
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	int C,D;cin>>C>>n>>m>>D>>q;
	for(int i=1;i<n;i++) for(int j=i+1;j<=n;j++) g[i][j]=g[j][i]=inf;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];g[i][i]=0;
		for(int j=1,x,ti;j<=k[i];j++){
			cin>>x>>ti;
			t[x].push_back({i,ti});
		}
	}
	for(int i=1;i<=m;i++){
		for(PII e1:t[i]){
			for(PII e2:t[i]){
				if(e1.f==e2.f) continue;
				g[e1.f][e2.f]=min(g[e1.f][e2.f],e1.s+e2.s);
				g[e2.f][e1.f]=min(g[e2.f][e1.f],e1.s+e2.s);
			}
		}
	}
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				g[i][j]=min(g[i][j],g[i][k]+g[k][j]);//老家伙又见面了，本以为这辈子都用不到了 
			}
		}
	}
	while(q--){
		int a,b,ans=inf;cin>>a>>b;
		for(PII e1:t[a]){
			for(PII e2:t[b]){
				ans=min(ans,e1.s+e2.s+g[e1.f][e2.f]);
			}
		}ans+=w[a]+w[b];
		cout<<ans<<"\n";
	}
	return 0;
}
/*
15:35:00 有思路了！！！ 
15:54:33 AC了！！！
17:54:46 检查：数组越界？数组大小！！注意，NM要分清，就因为w[N]而大样例爆炸了
18:11:24 感觉时间复杂度有点极限，CCF应该不会卡常吧 
期望得分100
预估难度：绿
已检查freopen 
*/
