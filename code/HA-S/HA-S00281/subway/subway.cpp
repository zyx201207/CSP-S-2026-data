#include<bits/stdc++.h>
using namespace std;
struct node{
	int id;
	int length;
	friend operator < (node a,node b){
		return b.length<a.length;
	}
};
int c,n,m,d,q;
int w[100005];
/********dui yu jie dian er yan************/
int cnt[100005];
int road[100005][105];
int t[100005][105];
/********dui yu lu xian er yan***********/
int idx[105]={-1};
int h[105][100005];
int vxt[105][500005];
int nxt[105][500005];
void add(int i,int u,int v){
	h[i][u]=++idx[i];vxt[i][idx[i]]=v;nxt[i][idx[i]]=idx[i]-1;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;cin>>k;int x[k+1];
		for(int j=1;j<=k;j++){
			cin>>x[j];
			cnt[x[j]]++;
			road[x[j]][cnt[x[j]]]=i;
			cin>>t[x[j]][cnt[x[j]]];
			/****************/
			if(j!=1){
				add(i,x[j],x[j-1]);
				add(i,x[j-1],x[j]);
			}
		}
	}
	for(int r=1;r<=q;r++){
		int x,y;
		cin>>x>>y;
		priority_queue<node>q;
		node tmp;tmp.id=x;tmp.length=w[x]+w[y];
		q.push(tmp);
		while(!q.empty()){
			tmp=q.top();q.pop();
			if(tmp.id==y){
				cout<<tmp.length<<endl;
				break;
			}
			if(cnt[tmp.id]==1){
				int p=h[road[tmp.id][1]][tmp.id];
				p=nxt[road[tmp.id][1]][p];
				node ntmp=tmp;ntmp.id=vxt[road[tmp.id][1]][p];
				q.push(ntmp);
			}
			else {
				tmp.length+=t[tmp.id][1];
				for(int i=2;i<=cnt[tmp.id];i++){
					node ntmp=tmp;ntmp.length+=(t[tmp.id][road[tmp.id][i]]);
					int p=h[road[ntmp.id][i]][ntmp.id];
				    p=nxt[road[ntmp.id][i]][p];ntmp.id=vxt[road[ntmp.id][i]][p];
					q.push(ntmp);
				}
			}
		}
	}
	return 0;
}
