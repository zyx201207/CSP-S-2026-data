#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=500005,M=300005;
int n,m;  //注意边数、点数 !!!!!
int a[N];   // 最终答案是否要开 long long？ 
int hd[M],to[N],nxt[N],tot; //M个点 N条边， 
int b[M],du[M];
ll dp[M];
int cnt[M];

void add(int x,int y){
	tot++;
	du[y]++;
	to[tot]=y;
	nxt[tot]=hd[x];
	hd[x]=tot;
}
queue<int> q;
void topo(){
	for(int i=1;i<=m;i++){
		if(du[i]==0){
			q.push(i);
		}
	}
	while(q.size()){
		int u=q.front();
		q.pop();
		for(int i=hd[u];i;i=nxt[i]){
			int v=to[i];
			dp[v]+=dp[u];
			du[v]--;
			if(du[v]==0){
				q.push(v);
			}
		}
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		cnt[a[i]]++;
	}
	for(int i=n;i>=1;i--){
		if(!b[a[i]]){
			dp[a[i]]=cnt[a[i]];
			if(i!=n) add(a[i],a[i+1]);
			b[a[i]]=1;
		}
	}
	topo();
	for(int i=1;i<=m;i++){
		cout<<dp[i];
		if(i!=m) cout<<" ";
	}
	return 0;
}
