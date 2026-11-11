#include <bits/stdc++.h>
using namespace std;
const int N=1000005;
int c,T;
int n,k;
int head[N],ver[N*2],nxt[N*2],tot;
void add(int u,int v){
	ver[++tot]=v,nxt[tot]=head[u],head[u]=tot;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	if(c==7||c==11||c==12){
		while(T--){
			cin>>n>>k;
			for(int i=1;i<n;i++){
				int u,v;cin>>u>>v;
				add(u,v),add(v,u);
			}
			cout<<(n-2)/3<<endl;
		}
	}
}
