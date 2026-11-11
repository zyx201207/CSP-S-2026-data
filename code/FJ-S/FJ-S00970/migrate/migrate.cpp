#include<bits/stdc++.h>
using namespace std;
#define inf 0x3f3f3f3f
const int N=5e5+5;
int c,t;
int n;
long long d;
int l,r;
int x[N];
vector<int> V[N];
int dis[N];
int vis[N];
int ans;
int st;
int num[N],cnt,len;
void spfa(int s,int t){
	dis[s]=0;
	st=1;
	num[++cnt]=s;
	vis[s]=1;
	len=1;
	while(len){
		int p=num[st];
		st++;
		len--;
		for(int i=0;i<V[p].size();i++){
			if(dis[V[p][i]]>=dis[i]+1){
				if(V[p][i]==t){
					if(dis[V[p][i]]==dis[i]+1) ans++;
					else ans=1;
				}
			    dis[V[p][i]]=dis[i]+1;
			    if(!vis[V[p][i]]) len++,num[++cnt]=V[p][i];
			}
		}
	}
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		memset(vis,0,sizeof(vis));
		memset(dis,inf,sizeof(dis));
		int tot=0;
		l=1,r=1;
		memset(x,0,sizeof(x));
		for(int i=1;i<=n;i++) scanf("%d",&x[i]);
		while(l<=n){
			while(r<=n&&x[l]+d>=x[r]) ++x[r];
			for(int i=l;i<=r-1;i++){
				V[l].push_back(i);
				V[i].push_back(l);
			}
		}
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				ans=0;
				spfa(i,j);
				if(ans==2) tot++;
			}
		}
		printf("%d\n",tot);
	}
	return 0;
}
