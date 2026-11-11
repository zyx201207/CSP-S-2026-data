#include <bits/stdc++.h>
using namespace std;
#define PII pair<int,pair<int,int> >
int c,n,m,dd,q;
int w[500005];
int k[505];
vector<int> l[500005];
vector<int> ll[500005];
int a[505][50005],t[505][50005];
int d[50005][505];
void diji(int s){
	priority_queue<PII,vector<PII>,greater<PII> > heap;
	for(int i=0;i<l[s].size();i++){
		heap.push({ll[s][i],{s,l[s][i]}});
		d[s][l[s][i]]=ll[s][i];
	}
	while(heap.size()){
		PII h=heap.top();
		heap.pop();
		int p1=h.second.first,p2=h.second.second,dis=h.first;
		for(int i=0;i<l[p1].size();i++){
			if(d[p1][l[p1][i]]>dis+ll[p1][i]){
				d[p1][l[p1][i]]=dis+ll[p1][i];
				heap.push({d[p1][l[p1][i]],{p1,l[p1][i]}});
			}
		}
		for(int i=1;i<=k[p2];i++){
			if(d[a[p2][i]][p2]>dis){
				d[a[p2][i]][p2]=dis;
				heap.push({dis,{a[p2][i],p2}});
			}
		} 
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>dd>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k[i];
		for(int j=1;j<=k[i];j++){
			cin>>a[i][j]>>t[i][j]; 
			l[a[i][j]].push_back(i);
			ll[a[i][j]].push_back(t[i][j]);
		}
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		for(int i=1;i<=m;i++)for(int j=1;j<=n;j++)d[i][j]=0x3f3f3f3f;
		diji(x);
		int ans=0x3f3f3f3f;
		for(int i=0;i<l[y].size();i--)ans=min(ans,d[y][l[y][i]]+ll[y][i]);
		cout<<ans+w[x]+w[y]<<'\n';
	}
	return 0;
}

