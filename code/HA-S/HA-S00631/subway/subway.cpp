#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,Q,w[500005],k,x[500005],y[500005],num;
long long dis[15000005],uu,vv,ans[100005];
priority_queue<pair<long long,int>,vector<pair<long long,int> >,greater<pair<long long,int> > >q;
map<pair<int,int>,int>mp;
int cnt,to[4000005],val[4000005],nxt[4000005],h[15000005];
//int f[4000005];
bool bj[15000005];
struct st{
	int a,b,pos;
}qj[100005];
bool cmp(st xx,st yy){
	if(xx.a!=yy.a) return xx.a<yy.a;
	return xx.b<yy.b;
}
void add(int u,int v,int w){
	cnt++;
	to[cnt]=v;
	//f[cnt]=u;
	val[cnt]=w;
	nxt[cnt]=h[u];
	h[u]=cnt;
	//cout<<h[1]<<'@'<<'\n';
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
		add(i,i+m,w[i]);
		add(i+m,i,w[i]);
	}
	
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>x[j]>>y[j];
			if(mp[make_pair(i,x[j])]==0){
				num++;
				//cout<<"route:"<<i<<" line station no:"<<j<<" station name:"<<x[j]<<"num:"<<2*m+num<<'\n'; 
				mp[make_pair(i,x[j])]=2*m+num;
			}
			add(x[j]+m,mp[make_pair(i,x[j])],y[j]);
			add(mp[make_pair(i,x[j])],x[j]+m,y[j]);
			if(j!=1){
				add(mp[make_pair(i,x[j])],mp[make_pair(i,x[j-1])],0);
				add(mp[make_pair(i,x[j-1])],mp[make_pair(i,x[j])],0);
			}
		}
	}
	
//	for(int i=1;i<=cnt;i++){
//		cout<<f[i]<<"->"<<to[i]<<':'<<val[i]<<'\n';
//	}
//	
	for(int z=1;z<=Q;z++){
		cin>>qj[z].a>>qj[z].b;
		qj[z].pos=z;
	}
	sort(qj+1,qj+Q+1,cmp);
	for(int z=1;z<=Q;z++){
		if(qj[z].a!=qj[z-1].a){
			for(int i=1;i<=2*m+num;i++){
				dis[i]=1e18;
				bj[i]=0;
			}
			dis[qj[z].a]=0;
			q.push(make_pair(0,qj[z].a));		
			while(!q.empty()){
				uu=q.top().second;
				q.pop();
				if(bj[uu]==1) continue;
				bj[uu]=1;
				for(int j=h[uu];j!=0;j=nxt[j]){
					vv=to[j];
					if(bj[vv]==0&&dis[vv]>dis[uu]+val[j]){
						dis[vv]=dis[uu]+val[j];
						q.push(make_pair(dis[vv],vv));
					}
				}
			}
		}
		//cout<<dis[1]<<' '<<dis[6]<<' '<<dis[11]<<' '<<dis[12]<<' '<<dis[7]<<' '<<dis[14]<<' '<<dis[15]<<' '<<dis[8]<<' '<<dis[3]<<'\n';
		//cout<<dis[b]<<'\n';
		ans[qj[z].pos]=dis[qj[z].b];
	}
	for(int z=1;z<=Q;z++){
		cout<<ans[z]<<'\n';
	}
	return 0;
}
