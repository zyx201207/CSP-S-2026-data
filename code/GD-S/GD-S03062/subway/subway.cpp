#include<bits/stdc++.h>
using namespace std;
#define int long long
int C,m,n,p,d,x,y,minn=1000000000000000000,a[500001],e[500001]={0};
bool sc[500001]={false};
vector<vector<int>> b(500001),d1(501),t(501);
void dfs(int i,int sum){
	if(sc[i]||sum>=minn||e[i]>=sum) return;
	e[i]=sum;
	for(int j=0;j<d1[i].size();j++){
		if(d1[i][j]==y){
			minn=sum;
			return ;
		}
	}
	sc[i]=true;
	for(int j=0;j<d1[i].size();j++) for(int k=0;k<b[d1[i][j]].size();k++) for(int k1=0;k1<d1[b[d1[i][j]][k]].size();k1++) if(d1[b[d1[i][j]][k]][k1]!=d1[i][j]) dfs(d1[b[d1[i][j]][k]][k1],sum+t[i][j]+a[b[d1[i][j]][k]]);
	sc[i]=false;
}
signed main(){
	freopen("subway.in","r",stdin);
	//freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&C,&n,&m,&d,&p);
	for(int i=1;i<=m;i++) scanf("%lld",&a[i]);
	for(int i=1;i<=n;i++){
		int k;
		scanf("%lld",&k);
		for(int j=1;j<=k;j++){
			int x,x1;
			scanf("%lld%lld",&x,&x1);
			t[i].push_back(x1),d1[i].push_back(x),b[x].push_back(i);
			
		}
	}
	for(int i=1;i<=p;i++){
		scanf("%lld%lld",&x,&y);
		minn=1000000000000000000;
		dfs(x,a[x]);
		memset(e,0,sizeof(e));
		printf("%lld\n",minn+a[y]);
	}
}
