#include<bits/stdc++.h>
#define int long long
using namespace std; 
const int N=5e4+100;
int c,n,m,b,q,w[N],ans,st,en,k[600],t[N][600],a[600][600]; //n为线路数量，t为时间，m为站数
void dij(){
	int len[N];
	bool pd[N];
	memset(len,0x3f,sizeof(len));
	memset(pd,0,sizeof(pd));
	len[st]=0;
	priority_queue<pair<int,int> ,vector<pair<int,int> >,greater<pair<int,int> > > q;
	q.push({0,st}); 
	while(!q.empty()){
		pair<int,int> tmp=q.top();
		q.pop();
		int wz=tmp.second;
		pd[wz]=true;
		if(wz==en){
			ans=tmp.first;
			break;
		}
		while(pd[q.top().second]&&!q.empty()) q.pop();
		for(int i=1;i<=n;i++){
			if(t[wz][i]<=ans){
				for(int j=1;j<=k[i];j++){
					if(pd[a[i][j]]) continue;
					int lc=t[a[i][j]][i];
					if(len[a[i][j]]<=lc+tmp.first+t[wz][i]) continue;
					len[a[i][j]]=lc+tmp.first+t[wz][i];
					q.push({len[a[i][j]],a[i][j]});
				}
			}
		}
	} 
	return;
} 
signed main(){ 
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	memset(t,0x3f,sizeof(t));
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&b,&q);
	for(int i=1;i<=m;i++) scanf("%lld",&w[i]); 
	for(int i=1;i<=n;i++){
		scanf("%lld",&k[i]);
		for(int j=1;j<=k[i];j++){
			int ts;
			scanf("%lld%lld",&a[i][j],&ts);
			t[a[i][j]][i]=ts;
		}
	} 
	while(q--){
		scanf("%lld%lld",&st,&en);
		ans=0x3f3f3f3f3f3f;
		dij();
		ans+=w[st]+w[en];
		printf("%lld\n",ans);
	} 
	return 0;
}
