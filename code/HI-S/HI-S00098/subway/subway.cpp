#include<bits/stdc++.h>
using namespace std;
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > p;
int c,n,m,d,q,cnt=0;
int w[500005];
int a[500005];
int t[500005];
vector<pair<int,int> > v[500005];
int f[500005],k[500005];
void dj(int x,int y){
	memset(f,0,sizeof(f));
	memset(k,0x7f,sizeof(k));
	p.push({0,x});
	k[x]=0;
	while(!p.empty()){
		pair<int,int> h=p.top();
		p.pop();
		int dis=h.second;
		int now=h.first;
		if(f[dis]==1) continue;
		else f[dis]=1;
		for(int j=0;j<v[dis].size();j++){
			int to=v[dis][j].second;
			if(k[to]>now+v[dis][j].first){
				k[to]=now+v[dis][j].first;
				p.push({k[to],to});
			} 
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	while(n--){
		int k; cin>>k;
		cnt++;
		for(int i=1;i<=k;i++){
			cin>>a[i]>>t[i];
		}
		for(int i=1;i<=k;i++){
			for(int j=i+1;j<=k;j++){
				v[a[i]].push_back({t[i]+t[j],a[j]});
				v[a[j]].push_back({t[i]+t[j],a[i]});
			}
		}
	}
	while(q--){
		int x,y; cin>>x>>y;
		dj(x,y);
		cout<<k[y]+w[x]+w[y]<<endl;
	}
	return 0;
}
