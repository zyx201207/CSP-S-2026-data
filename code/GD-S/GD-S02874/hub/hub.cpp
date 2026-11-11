#include<bits/stdc++.h>
//#define int long long
using namespace std;
const int MAXN=1e6+5;
int c,n,m,k,t;
vector<int> g[MAXN];
int dis[MAXN];
bool vis[MAXN];
queue<int> q;
int fa[MAXN];
int getfa(int x){
	if(fa[x]==x) return x;
	fa[x]=getfa(fa[x]);
	return fa[x];
}
void bfs(){
	while(!q.empty()){
		int x=q.front();
		q.pop();
		for(int v:g[x]){
			if(dis[v]==-1){
				dis[v]=dis[x]+1;
				q.push(v);
			}
		}
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin.sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>t;
	//记得多测清空!!!!!! 
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			g[i].clear();
		}
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
			g[x].push_back(y);
			g[y].push_back(x);
		}
		int ans=1919810;
		for(int i=1;i<=(1<<n);i++){
			int num=__builtin_popcount(i);
			if(num!=k) continue;
			for(int j=1;j<=n;j++){
				dis[j]=-1;
				fa[j]=j;
			}
			for(int j=1;j<=n;j++){
				if((1<<(j-1))&i){
					q.push(j);
					dis[j]=0;
				}
			}
			bfs();
			int res=0;
			num=0;
			for(int j=1;j<=n;j++){
				if((1<<(j-1))&i){
					for(int v:g[j]){
						if(dis[v]==0){
							fa[getfa(j)]=getfa(v);
						}
					}
				}
			}
			for(int j=1;j<=n;j++){
				if((1<<(j-1))&i){
					if(fa[j]==j) num++;
				}
				res=max(res,dis[j]);
			}
			if(num!=2) continue;
			ans=min(ans,res);
//			cout<<i<<" "<<num<<'\n';
		}
		cout<<ans<<'\n';
	}
	
	return 0;
}



/*
考生不能在注释中写侮辱性话语、歌词、诗词、散文等与考试无关的话语，若有违反可能会收到取消成绩或以上处分。这有什么原因吗。？ 

我想这背后一定出自___的深层考量罢。具体的用意是不应该揣摩的。

但我相信伟大的宽宏无量的___对他善良的____是不会因为这样就随便取消____的____的。

如果我真被____了，至少还能上个迷惑行为大赏吧。 

Drifting in endless ocean
Promises of something better
A hundred days of silence
Finding something 
Anything to keep us
From falling under
So 'till we meet again
Just know I'll 
come for you
So in the dark
We'll run
Bearing our tattered woven hearts
And come the dawn 
We'll be gone
So don't look away
Don't look away
And to the dark
We'll belong
Shoulder to shoulder folded strong
And come the dawn
We'll be gone
So don't look away
Don't look a-

I love xyl
but she doesn't
I remember the day she asked me
if i could have lunch with her
but i wasn't there
i regret
in fact
we don't talk anymore
i just can't do anything
am i wasting time
idk
i have a lot to say

AFO.
sometimes we have to accept the truth
at least my OI life is memoriable

To impress her it's too damn hard
To stay loyal without going too far

*/
