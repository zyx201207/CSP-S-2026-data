#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,s[505005],v1,v2,w,st,ed;
int mn,mp[505][505005];
struct edge{
	int to,wt;
};
struct node{
	int k,tm;
};
vector<edge>a[505005];
queue<node>qu;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>s[i];
	for(int i=1;i<=n;i++){
		scanf("%d",&w);
		for(int j=1;j<=w;j++){
			scanf("%d%d",&v1,&v2);
			a[v1].push_back({m+i,v2});
			a[m+i].push_back({v1,v2});//a[st][i]:tgt,dis to tgt hall
		}
	}
	for(int i=1;i<=n;i++){
		memset(mp[i],0x3f,sizeof(mp[i]));
		mp[i][m+i]=0;
		qu.push({i+m,0});
		while(qu.size()){
			node hd=qu.front();
			qu.pop();
			int stt=hd.k;
			for(int j=0;j<a[stt].size();j++){
				edge tmp=a[stt][j];
				int tgt=tmp.to;
				if(mp[i][tgt]>hd.tm+tmp.wt){
					mp[i][tgt]=hd.tm+tmp.wt;
					qu.push({tgt,hd.tm+tmp.wt});
				}
			}
		}
	} 
	for(int i=1;i<=q;i++){
		cin>>st>>ed;
		mn=2e9;
		for(int j=1;j<=n;j++)mn=min(mn,mp[j][st]+mp[j][ed]);
		cout<<mn+s[st]+s[ed]<<endl;
	}
	return 0;
}
