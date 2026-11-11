#include<bits/stdc++.h>
using namespace std;
struct station{
	int s,t;
};
struct node{
	int l,n,t;
};
vector<node>v[500005];//每个站台联通的车站 
int w[500005];//每一站出站台时间 
int u[500005]; //有没有去过 
int d[500005];
int f(int e,int s){
	queue<int>q;
	q.push(s);
	while(q.size()>0){
		int x=q.front();
		q.pop();
		for(int i=0;i<v[x].size();i++){
			int xx=x,pp=0;
			bool f=0;
			for(int j=0;j<v[v[x][i].n].size();j++){
				if(v[v[x][i].n][j].l==v[x][i].l&&v[v[x][i].n][j].n==x){
					xx=v[x][i].n;
					pp=j;
					f=1;
					break;
				}
			}
			if(u[v[x][i].n]==0&&d[v[x][i].n]!=-1){
				if(!f){
					d[xx]=d[x]+v[x][i].t+v[v[x][i].n][pp].t;
				}
				u[xx]=1;
				q.push(xx);
			}
		}
	}
	return d[e];
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int n,m,dd,p;
	cin>>n>>n>>m>>dd>>p;
	for(int i=0;i<m;i++){//进站时间 
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){//输入(站台 
		int k,x,y;
		cin>>k;
		station a[k];
		for(int j=0;j<k;j++){
			cin>>x>>y;
			a[j]={x,y};
		}
		for(int j=1;j<k;j++){
			v[a[j-1].s].push_back({i,a[j].s,a[j].t});
			v[a[j].s].push_back({i,a[j-1].s,a[j-1].t});
		}
	}
	for(int qq=0;qq<p;qq++){//每个计划 
		int x,y,z=0;
		cin>>x>>y;
		for(int i=0;i<=m;i++){
			d[i]=-1;
			u[i]=0;
		}
		d[x]=0;
		z+=w[x-1]+w[y-1];
		cout<<z+f(x,y)<<'\n';
	}
}
