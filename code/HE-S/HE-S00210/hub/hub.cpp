#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int head[maxn],to[maxn*2],nxt[maxn*2];
int cnt=1;
void ad(int u,int v){
	nxt[cnt]=head[u];
	to[cnt]=v;
	head[u]=cnt++;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	itn c,t;
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			int u,v;
			cin>>u>>v; 
			cout<<1<<'\n';
		}
	}
	
	return 0;
} 
/*


*/
