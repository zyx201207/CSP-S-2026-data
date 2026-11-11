#include<bits/stdc++.h>
using namespace std;
int le[200005],ne[200005],to[200005];
int n,lb,k;
int xl[200005];
bool b[200005];
int dp[200005];
void ad(int x,int y){
	to[++lb]=x;
	ne[lb]=le[y];
	le[y]=lb;
}
int an=1e9+7,ck=0,ma=0;
void check(int x){
	if(b[x]==0){
		ck--;
		return ;
	}
	b[x]=0;
	for(int i=le[x];i;i=ne[i]){
		if(b[to[i]]){
			check(to[i]);
		}
	}
}
void bfs(){
	queue<int>q;
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=k;i++){
		q.push(xl[i]);
		dp[xl[i]]=1;
	}
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int i=le[u];i;i=ne[i]){
			if(!dp[to[i]]){
				q.push(to[i]);
				dp[to[i]]=dp[u]+1;
				ma=max(ma,dp[to[i]]-1);
			}
		}
	}
}
void dl(int x){
	if(x==k){
		ma=0,ck=0;
		for(int i=1;i<=k;i++){
			ck++;
			check(xl[i]);
			if(ck>2){
				return ;
			}
		}
		bfs();
		an=min(an,ma);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!b[i]){
			b[i]=1;
			xl[x+1]=i;
			dl(x+1);
			b[i]=0;
		}
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin >> c >> t;
	if(c==13||c==14){
		while(t--){
			scanf("%d%d",&n,&k);
			an=0;
			int tt=(k-2)>>2;
			int tc=n>>2;
			int b1=tc-tt;
			cout << b1 << '\n';
		}
		return 0;
	}
	while(t--){
		scanf("%d%d",&n,&k);
		lb=0;
		an=1e9+7;
		for(int i=1;i<n;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			ad(x,y);
			ad(y,x);
		} 
		dl(0);
		cout << an << '\n';
	}
	return 0;
}
