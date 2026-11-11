#include<bits/stdc++.h>
using namespace std;
long long a,n,m,r,io,k,s,e,d,Q,C,maxx=-1,maxx2=-1,ioi,ans=0x3fffffff;
long long w[500505],u,v,dis[505005],b[505005],t;
long long to[1001005],val[1001005],h[1001005],nxt[1001005],cnt;
priority_queue<pair<int,long long>,vector<pair<int,long long> >,greater<pair<int,long long> > > q;
void add(int a,int b,int c){
	to[++cnt]=b;
	val[cnt]=c;
	nxt[cnt]=h[a];
	h[a]=cnt;
}
void dij(long long s){
	for(int i=1;i<=n+m;i++){
		dis[i]=0x3fffffff;
		b[i]=0;
	}
	dis[s]=0;
	while(!q.empty()){
		q.pop();
	}
	q.push({s,0});
	while(!q.empty()){
		int k=q.top().first;
		q.pop();
		if(b[k]==1){
			continue;
		}
		b[k]=1;
		for(int j=h[k];j!=0;j=nxt[j]){
			int v=to[j];
			if(b[v]==0&&dis[v]>dis[k]+val[j]){
				dis[v]=dis[k]+val[j];
				q.push({v,dis[v]});
			}
		}
	}
	return;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>C>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n-1;i++){
			cin>>u>>v;
			add(u,v,1);
			add(v,u,1);
		}
		if(k!=2){
			cout<<(n-k)/(k+1);
		}
		else{
//			dij(1);
//			for(int i=1;i<=n;i++){
//				cout<<dis[i]<<endl;
//			}
			for(int i=1;i<=n;i++){
				dij(i);
				maxx=0;
				maxx2=0;
				for(int j=1;j<=n;j++){
					if(dis[j]>maxx){
						maxx=dis[j];
						ioi=j;
					}
				}
				for(int j=1;j<=n;j++){
					if(j==ioi){
						continue;
					}
					if(dis[j]>maxx2){
						maxx2=dis[j];
						ioi=j;
					}
					maxx=(maxx-1)/2;
					ans=min(ans,max(maxx,maxx2));
				}
//				cout<<maxx<<' '<<maxx2<<endl;
				
//				cout<<maxx<<' '<<maxx2<<endl;
			}
			cout<<ans<<'\n';
		}
	}
	return 0;
}
