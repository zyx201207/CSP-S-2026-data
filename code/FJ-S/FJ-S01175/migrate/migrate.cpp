#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5,MAXV=505;
typedef long long ll;
typedef pair<ll,ll> pii;
#define fi first
#define se second
#define qwq(x) freopen(x ".in","r",stdin);freopen(x ".out","w",stdout);
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define rrep(x,y,z) for(int x=z;x>=y;x--)
const ll inf=1e16;

//18:14 add the word next line,BruteForce hao shan,bai xie BruteForce
//Chtholly bless me
//Chtholly,Willem and Senioris

int t;
int n;
ll d,x[MAXN];
int cnt[MAXN];
int dist[MAXN];

void bfs(int s){
	fill(cnt+1,cnt+n+1,0);
	fill(dist+1,dist+n+1,0);
	queue<int>q;
	q.push(s);
	cnt[s]=1;
	while(q.size()){
		int u=q.front();q.pop();
		rep(i,u+1,n){
			if(x[u]<x[i]-d)break;
			if(dist[i]==dist[u]+1){
				cnt[i]+=cnt[u];
			}else if(dist[i]==0){
				cnt[i]+=cnt[u];
				dist[i]=dist[u]+1;
				q.push(i);
			}
		}
	}
}

void solve(){
	memset(x,0,sizeof(x));
	ll ans=0;
	scanf("%d %lld",&n,&d);
	rep(i,1,n){
		scanf("%lld",x+i);
	}
	rep(i,1,n){
		bfs(i);
		rep(j,i+1,n){
			if(cnt[j]==2)ans++;
		}
	}
	printf("%lld\n",ans);
}

int main(){
	#ifndef off
	qwq("migrate");
	#endif
	
	scanf("%*d %d",&t);
	while(t--)solve();
}