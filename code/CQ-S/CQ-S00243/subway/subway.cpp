#include<bits/stdc++.h>
using namespace std;
int n,m,D,q;
int a[500005];
struct node{
	int to,nxt,w;
}e[30500005];
int h[1000005],cnt=0;
void add(int x,int y,int z){
	cnt++;
	e[cnt].to=y;
	e[cnt].w=z;
	e[cnt].nxt=h[x];
	h[x]=cnt;
}
int d[1000005];
int dij(int s,int t){
	for(int i=1;i<=m*(n+1);i++) d[i]=INT_MAX;
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
	d[s]=0; q.push({d[s],s});
	while(!q.empty()){
		int x=q.top().second;
		int w=q.top().first;
		q.pop();
		if(w!=d[x]) continue;
		for(int i=h[x];i;i=e[i].nxt){
			int y=e[i].to;
			if(d[x]+e[i].w<d[y]){
				d[y]=d[x]+e[i].w;
				q.push({d[y],y});
			}
		}
	}
	return d[t];
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int CC;
	cin>>CC>>n>>m>>D>>q;
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		int k; cin>>k;
		int last=-1;
		for(int j=1;j<=k;j++){
			int x,t; cin>>x>>t;
			add(x+n*m,x+(i-1)*m,t); add(x+(i-1)*m,x+n*m,t);
//			cout<<x+(i-1)*m<<' '<<x+n*m<<' '<<t<<endl;
			if(last!=-1){
//				cout<<last<<' '<<x+(i-1)*m<<' '<<0<<endl;
				add(last,x+(i-1)*m,0); add(x+(i-1)*m,last,0);
			}
			last=x+(i-1)*m;
		}
//		cout<<endl;
	}
	while(q--){
		int s,t; cin>>s>>t;
		cout<<a[s]+a[t]+dij(s+n*m,t+n*m)<<endl;
	}
	return 0;
}
/*
*/
