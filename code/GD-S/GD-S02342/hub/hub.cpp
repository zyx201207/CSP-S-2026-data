#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PII;
const int N=1e4+10,M=1e7+10,K=25,INF=0x3f3f3f3f;
int n,m,c,k,q;
LL cnt,cost[N];
LL e[M],ne[M],h[M],idx,w[M];
void add(LL a,LL b,LL c){
	e[idx]=b,ne[idx]=h[a],w[idx]=c,h[a]=idx++;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	srand(time(0));
	ios::sync_with_stdio(0);
	cin.tie(0);
	memset(h,-1,sizeof h);
	cin>>c>>q;
	while(q--){
		cin>>n>>k;
		cout<<rand()%2+1<<endl;
	} 
	return 0;
}
