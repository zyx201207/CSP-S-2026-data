#include <bits/stdc++.h>
using namespace std;
#define I cin>>
#define O cout<<
typedef long long ll;
const int N=1e5+5;
int C,T,n,m,x,y,mxl[N],cmxl[N];
vector<int> dp[N][3][3],edge[N];
void dfs(int rt,int fa){
	for(auto it:edge[rt]){
		if(it!=fa){
			dfs(it,rt);
			if(mxl[it]+1>mxl[rt]) cmxl[rt]=mxl[rt],mxl[rt]=mxl[it]+1;
			else if(mxl[it]+1>=cmxl[rt]) cmxl[rt]=mxl[it]+1;
		}
	}
}
void dfs2(int rt,int fa){
	for(auto it:edge[rt]){
		if(it!=fa) dfs2(it,rt);
	}
	dp[rt][0][0][0]=mxl[rt];
	for(auto it:edge[rt]){
		if(it!=fa){
			for(int i=0;i<m;i++){
				dp[rt][1][0][i]=min(max(dp[it][1][0][i]+1,(mxl[rt]==mxl[it]+1)?(cmxl[rt]):(mxl[rt])),max(dp[it][1][2][i],max((mxl[rt]==mxl[it]+1)?(cmxl[rt]):(mxl[rt]),1)));
				dp[rt][1][1][i]=min(max(dp[it][1][1][i])); 
			} 
		}
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	I C >> T;
	while(T--){
		I n >> m;
		for(int i=1;i<=m;i++){
			I x >> y;
			edge[x].push_back(y);
			edge[y].push_back(x);
		}
		for(int i=1;i<=n;i++){
			for(int s1=0;s1<3;s1++){
				for(int s2=0;s2<3;s2++){
					if(s1==1){
						dp[i][s1][s2].clear();
						dp[i][s1][s2].resize(m);
					}else{
						dp[i][s1][s2].resize(1);
						dp[i][s1][s2][0]=0;
					} 
				} 
			}
		}
		dfs(1,0);
		
	}
	return 0;
}

/*
我是The_Que

我进不了WC了

也许能进NOIP吧

240pts

差一点点就300啊啊啊啊啊啊！

凭什么？

我就不该去搞T4

浪费了我1h

byebye！ 
*/
