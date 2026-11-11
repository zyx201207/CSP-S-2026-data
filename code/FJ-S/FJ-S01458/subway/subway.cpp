#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL N=555,M=555555,INF=(1LL<<60);
LL cost[N][N]; 
LL c,n,m,d,q,k,ans;
LL w[M];
vector <LL> w2[M];
vector <LL> s[M]; 
LL read(){
	char c=getchar();
	while(c<'0'||c>'9'){
		c=getchar();
	}
	LL ans=0;
	while(c>='0'&&c<='9'){
		ans=ans*10+c-'0';
		c=getchar();
	}
	return ans;
} 
void check(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cout<<cost[i][j]<<" ";
		}
		cout<<'\n';
	}
}
void fl(){
//	check();
	for(int i=1;i<=n;i++){
		for(int k=1;k<=n;k++){
			for(int j=1;j<=n;j++){
				cost[i][j]=min(cost[i][j],cost[i][k]+cost[k][j]);
			}
		}
	}
//	check(); 
}
LL f(LL i,LL j){
	return cost[i][j];
}
void init(){
	//start
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			cost[i][j]=INF;
			if(i==j){
				cost[i][j]=0;
			}
		}
	}
	//¸³Öµ
	while(m--){
		for(int i=0;i<s[m].size();i++){
			for(int j=0;j<s[m].size();j++){
//				s[m][i]   s[m][j]
				cost[s[m][i]][s[m][j]]=min(cost[s[m][i]][s[m][j]], w2[m][i]+w2[m][j]);
			}
		}
	} 
	fl();
	return ; 
} 
int main(){
	//c, n, m, d, q
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		w[i]=read();
	}
	LL t,z;
	for(int i=1;i<=n;i++){
		k=read();
		while(k--){
			z=read();
			t=read();
			w2[z].push_back(t);
			s[z].push_back(i);
		}
	}
	init();
	LL a,b;
	while(q--){
		a=read();b=read();
		ans=INF;
		for(int i=0;i<s[a].size();i++){
			for(int j=0;j<s[b].size();j++){
				ans=min(ans,w[a]+w[b]+w2[a][i]+w2[b][j]+f(s[a][i],s[b][j]));
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
