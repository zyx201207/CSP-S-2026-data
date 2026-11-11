#include<bits/stdc++.h>
using namespace std;
const int N=2000005;
int c,T,n,k,cnt,h[N];

struct node{
	int to,nex;
}e[N*2];

void add(int u,int v){
	e[++cnt].nex=h[u];
	e[cnt].to=v;
	h[u]=cnt;
	
}

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		scanf("%d%d",&n,&k);
		for(int u,v,i=1;i<n;i++){
			scanf("%d%d",&u,&v);
			add(u,v);
			add(v,u);
		}
		int m=n/2,d=m+1;
		printf("%d\n",((d+1)/4-((k-2)/4)));
	}
	
	
}

