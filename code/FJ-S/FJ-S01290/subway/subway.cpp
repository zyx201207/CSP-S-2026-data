#include <bits/stdc++.h>
using namespace std;
const int N=510,M=5e5+10;
int c,n,m,d,p;
//struct node2{
//	int t;
//	
//}a[N];
int w[N];
int len[N];
int dis[N];
bool v[N];
struct mo{
	int a,t;
};
vector<mo> line[N];
struct node{
	int dis,to;
};
vector<node> t[M];
node make(int x,int y){
	node num;
	num.to=x,num.dis=y;
	return num;
}
mo make1(int x,int y){
	mo num;
	num.a=x,num.t=y;
	return num;
}
//bool operator< (node x,node y){
//	return x.dis<y.dis;
//}
void solov(){
	int x,y;
	cin>>x>>y;
	int ans=w[x]+w[y];
	memset(dis,0x3f,sizeof(dis));
	dis[x]=0;
//	q.push(make(0,x));
	for(int i=1;i<=m;i++){
		int minn=1e9,k=0;
		for(int j=1;j<=m;j++)
			if(!v[j]&&dis[j]<minn){
				minn=dis[j];
				k=j;
			}
		if(k==0) break;
		v[k]=1;
		for(int j=0;j<t[k].size();j++){
			if(!v[t[k][j].to]&&dis[k]+t[k][j].dis<dis[t[k][j].to]){
				dis[t[k][j].to]=dis[k]+t[k][j].dis;
			}
		}
	}
	cout<<dis[y]+ans<<"\n";
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>len[i];
		for(int j=1;j<=len[i];j++){
			int x,y;
			cin>>x>>y;
			line[i].push_back(make1(x,y));
//			t[i][line[i][j].a]=line[i][j].t;
		} 
	}
//	if(c>=7&&c<=11){
		for(int i=1;i<=n;i++){
			mo l=line[i][0],r=line[i][1];
			t[l.a].push_back(make(r.a,l.t+r.t));
			t[r.a].push_back(make(l.a,l.t+r.t));
		}
		while(p--){
			memset(v,0,sizeof(v));
			solov();
		}
//	}
	return 0;
}

