#include<bits/stdc++.h>
using namespace std;
const int N=15;
vector<int> e[N];
bool s[15];
int n,k,vis[N],qwq,c,t;
int dfs(int pos,int stts,int stp){
	vis[pos]=1;
	if((stts>>(pos-1))&1)return stp;
	int add=110101001;
	for(auto ed:e[pos]){
		if(vis[ed])continue;
		add=min(dfs(ed,stts,stp+1),add);
	}
	return add;
}
void df(int i){
	for(auto ed:e[i]){
		if(s[ed]){s[ed]=0;df(ed);}
	}
}
bool intwo(int val){
	memset(s,0,sizeof(s));int anss=0;
	for(int i=1;i<=n;i++)if((val>>(i-1))&1)s[i]=1;
	for(int i=1;i<=n;i++){
		if(s[i]){
			df(i);
			anss++;
		}
		if(anss>2)return false;
	}return true;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		int ans=0,tott=11451419;
		for(int i=1;i<=14;i++)e[i].clear();
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		for(int i=0;i<=(1<<n)-1;i++){
			ans=0;
		if(__builtin_popcount(i)!=k)continue;
			for(int j=1;j<=n;j++){
				if((i>>(j-1))&1){
					continue;
				}
				memset(vis,0,sizeof(vis));
				qwq=0;
				ans=max(ans,dfs(j,i,0));
			}
			if(intwo(i))
			tott=min(tott,ans);
		}
		cout<<tott<<"\n";
	}
	return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
 */
