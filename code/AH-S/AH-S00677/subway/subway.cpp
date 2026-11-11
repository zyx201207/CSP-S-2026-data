#include<bits/stdc++.h>
using namespace std;
const int LN=510,KM=500010;
int csdbh,dd,ln,km,q;
long long w[KM],dis;
struct Node{
	int to;
	long long val;
}tmp;
vector<Node> G[KM];
bool vis[KM];
void dfs(int u,int st,long long sum){
	if(u==st){
		dis=min(dis,sum);
		return ;
	}
	int len=G[u].size();
	for(int i=0;i<len;i++){
		int v=G[u][i].to,ww=G[u][i].val;
		if(!vis[v]){
			vis[v]=true;
			dfs(v,st,sum+ww);
			vis[v]=false;
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>csdbh>>ln>>km>>dd>>q;
	for(int i=1;i<=km;i++){
		cin>>w[i+500];
	}
	
	int k,b;
	long long va;
	for(int a=1;a<=ln;a++){
		cin>>k;
		for(int i=1;i<=k;i++){
			cin>>b>>va;
			b+=500;
			tmp.to=b,tmp.val=va;
			G[a].push_back(tmp);
			tmp.to=a;
			G[b].push_back(tmp);
		}
	}
	
	int x,y;
	for(int i=1;i<=q;i++){
		dis=0x7f7f7f7f;
		memset(vis,0,sizeof vis);
		cin>>x>>y;
		x+=500,y+=500;
		dfs(x,y,0);
		cout<<dis+w[x]+w[y]<<endl;
	}
	return 0;
}

