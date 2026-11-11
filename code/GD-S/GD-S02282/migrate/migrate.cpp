#include<iostream>
#include<queue>
#define ll long long
using namespace std;
const int N=2000005,M=25000005,inf=0x3f3f3f3f;//2.5e7
int idx,h[N],f[N],cnt[N],ind[N],tmpd[N];
struct Edge{
	int v,nx;
}e[M];
ll a[N];
void add(int u,int v){
	e[++idx]={v,h[u]};
	h[u]=idx;
}
void sol(){//O(n^2)
	int T;
	cin>>T;
	while(T--){//∂‡≤‚≤ª«Âø’,__________ 
		int n;
		ll d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>a[i];
		int ans=0;
		idx=0;
		for(int s=n;s>=1;s--){//µπ–Ú£∫±‹√‚indÀ„¥Ì 
			f[s]=0;
			cnt[s]=1;
			ind[s]=0;
			h[s]=-1;
			for(int v=s+1;v<=n;v++){
				if(a[v]-a[s]<=d){
					add(s,v);
					ind[v]++;
				}
				f[v]=inf;
				cnt[v]=0;
				tmpd[v]=ind[v];
			}
			queue<int>q;
			q.push(s);//tupo
			while(!q.empty()){
				int u=q.front();
				q.pop();
				for(int i=h[u];i;i=e[i].nx){
					int v=e[i].v;
					if(f[v]>f[u]+1){
						f[v]=f[u]+1;
						cnt[v]=cnt[u];
					}else if(f[v]==f[u]+1)cnt[v]+=cnt[u];
					if(!--tmpd[v])q.push(v);
				}
			}
			for(int v=s+1;v<=n;v++){
				if(cnt[v]==2)ans++;
			}
		}
		cout<<ans<<'\n';
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c;
	cin>>c;
	if(c<=10){
		sol();
		return 0;
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

1
2
*/
