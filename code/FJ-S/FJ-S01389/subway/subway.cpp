#include<bits/stdc++.h>
#define int long long
using namespace std;
struct P{
	int v,w;
};
struct H{
	int x,w;
	bool operator <(const H &z)const{
		return w>z.w;
	}
};
int c,n,m,d,q,w[500005],tz;
bool b[500505];
vector<P>v[500505];
int dj(int x,int y){
	priority_queue<H>q;
	for(int i=1;i<=m;i++){/*to[i]=LLONG_MAX;*/b[i]=0;}
	for(int i=500001;i<=n+500000;i++){/*to[i]=LLONG_MAX;*/b[i]=0;}
	b[x]=1;
	q.push({x,0});
	while(!q.empty()){
		int t=q.top().x,tmp=q.top().w;
		q.pop();
		if(t==y)return tmp;
		for(auto a:v[t]){
			if(!b[a.v]){
				b[a.v]=1;
				q.push({a.v,tmp+a.w});
			}
		}
	}
	return 0;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){cin>>w[i];}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;
			cin>>a>>t;
			tz=t;
			v[500000+i].push_back({a,t}); 
			v[a].push_back({500000+i,t});
		}
	}
	if(q<=200){
		for(int i=1;i<=q;i++){
			int x,y;
			cin>>x>>y;
			cout<<w[x]+w[y]+dj(x,y)<<'\n';
		}
	}else{
		for(int i=1;i<=q;i++){
			int x,y;
			cin>>x>>y;
			cout<<w[x]+w[y]<<'\n';
		}
	}
	return 0;
}
