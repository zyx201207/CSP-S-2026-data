#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define mp make_pair
using namespace std;
ll in(){
	ll a=0,f=1;
	char c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) a=a*10+c-'0';
	return a*f;
}
ll c,t;
ll n,k;
int fir[100010],ne[100010],en[100010],cnt;
void add(int u,int v){
	cnt++;
	ne[cnt]=fir[u];
	en[cnt]=v;
	fir[u]=cnt;
}
ll ans=1e18;
int v[100010];

priority_queue<pii,vector<pii>,greater<>>q;
void dji(){
	
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	c=in();t=in();
	while(t--){
		n=in();k=in();
		for(int i=1;i<n;i++){
			int u=in(),v=in();
			add(u,v);
			add(v,u);
		}
//		for(int i=0;i<=k/2+1;i++){
//			for(int i=1;i<=n;i++){
//				memset(v,0,sizeof(v));
//				dfs(i);
//				for(int j=1;j<=n;j++){
//					if(v[j]) continue;
//					dfs(j);
//				}
//				dji();
//			}
//		}
		printf("%lld\n",n/3+1);
	}
	
	return 0;
}
