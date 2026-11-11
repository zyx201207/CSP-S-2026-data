#include<bits/stdc++.h>
using namespace std;
const int N=2000005;
int c,t;
int n,k;
struct edge{
	int to,nextt;
}e[N<<1];
int fir[N];int ecnt=0;
void eadd(int u,int v){
	e[++ecnt].to=v,e[ecnt].nextt=fir[u],fir[u]=ecnt;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	scanf("%d%d",&c,&t);
	while(t--){
		scanf("%d%d",&n,&k);
		for(int i=1;i<n;i++){
			int u,v;
		}
	}
	return 0;
}
