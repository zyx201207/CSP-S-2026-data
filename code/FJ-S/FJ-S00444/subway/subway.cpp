#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q;
long long a[500005];
long long t[500005][2];
long long p[505][505];
bool vis[505];
struct Node{
	long long v,w;
	operator< (const Node& other) const{
		return v<other.v;
	}
};
vector<Node>ve[500005];
struct Node2{
	long long v,w;
	operator< (const Node2& other) const{
		return w>other.w;
	}
};
priority_queue<Node2>pq;
void ddd(long long x){
	while(!pq.empty())pq.pop();
	for(int i=1;i<=m;i++)vis[i]=0;
	pq.push({x,0ll});
	p[x][x]=0;
	while(!pq.empty()){
		Node2 ee=pq.top();
		pq.pop();
		if(!vis[ee.v]){
			vis[ee.v]=1;
			for(Node e:ve[ee.v]){
				p[x][e.v]=min(p[x][e.v],p[x][ee.v]+e.w);
				pq.push({e.v,p[x][e.v]});
			}
		}
	} 
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>t[i][0]>>t[i][1];
		}
		for(int x=1;x<=k-1;x++){
			for(int y=x+1;y<=k;y++){
				ve[t[x][0]].push_back({t[y][0],t[x][1]+t[y][1]});
				ve[t[y][0]].push_back({t[x][0],t[x][1]+t[y][1]});
			}
		}
	}
	for(int i=1;i<=m;i++){
		sort(ve[i].begin(),ve[i].end());
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			p[i][j]=1e18+7;
		}
	} 
	for(int i=1;i<=q;i++){
		long long x,y;
		cin>>x>>y;
		if(p[x][y]!=1e18+7){
			cout<<p[x][y]+a[x]+a[y]<<endl;
		}else if(p[y][x]!=1e18+7){
			cout<<p[y][x]+a[x]+a[y]<<endl;
		}else{
			ddd(x);
			cout<<p[x][y]+a[x]+a[y]<<endl;
		}
	}
} 
