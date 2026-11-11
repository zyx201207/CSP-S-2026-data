#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,t,n,k;
vector<int>g[100010];
int main(){
freopen("hub.in","r",stdin);
freopen("hub.out","w",stdout);

scanf("%d%d",&c,&t);
while(t--){
	scanf("%d%d",&n,&k);
	for(int i=1;i<n-1;i++){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
}
return 0;
}
/*
100+50+24+0
suiranhaishicai
danshizhishaomeiquniannamequlehaha 
jinniantulunzenmenameduo/kk
tulunwangchaole
*/
