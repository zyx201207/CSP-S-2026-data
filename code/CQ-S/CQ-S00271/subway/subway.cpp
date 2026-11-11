#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int x,y;
int v[25],h[25];
int b[20010][25];
int zd[20010][505],bj[20010][505];
int dj(){
	priority_queue <pair<pair<int,int>,int>,vector<pair<pair<int,int>,int>>,greater<pair<pair<int,int>,int>>> p;
	p.push({{0,0},x});
	memset(zd,0x3f,sizeof(zd));
	memset(bj,0,sizeof(bj));
	zd[x][0]=0;
	while(p.size()!=0){
		pair<pair<int,int>,int> q=p.top();
		p.pop();
		int zz=q.first.first,jj=q.first.second,dd=q.second;
		if(bj[dd][jj]==1){
			continue;
		}
		bj[dd][jj]=1;
		if(dd==x){
			for(int i=1;i<=n;i++){
				if(i!=jj){
					zd[dd][i]=min(zd[dd][i],zz+v[dd]+h[i]);
					p.push({{zd[dd][i],i},dd});
				}
			}
		}else{
			for(int i=1;i<=n;i++){
				if(i!=jj){
					zd[dd][i]=min(zd[dd][i],zz+2*h[dd]);
					p.push({{zd[dd][i],i},dd});
				}
			}	
		}
		for(int i=1;i<=m;i++){
			if(i!=dd && bj[i][jj]==0 && (b[dd][i]==jj || dd==x)){
				zd[i][b[dd][i]]=min(zd[i][b[dd][i]],zz);
				p.push({{zd[i][b[dd][i]],b[dd][i]},i});
			}
		}
	}
	int s=1e9;
	for(int i=1;i<=n;i++){
		s=max(s,zd[y][i]);
	}
	return h[y]+v[y]+s;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>v[i];
	}
	for(int i=1;i<=n;i++){
		int o;
		cin>>o;
		int k1=0,t1=0;
		for(int i=1;i<=o;i++){
			int k=0,t=0;
			cin>>k>>t;
			b[k1][k]=i;
			b[k][k1]=i;
			h[k]=t;
		}
	}
	while(q--){
		cin>>x>>y;
		cout<<dj()<<"\n";
	}
	return 0;
}
