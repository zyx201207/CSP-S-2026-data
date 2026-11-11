#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
const int INF=0x3f3f3f3f;
int c,n,m,d,q,w[N],a[510][100010],t[1010][1010],flag[N+N];
vector<int> g[N];
struct node{
	int no,ti,la;
};
void bfs(int qd,int zd){
	queue<node> q;
	for(int i=1;i<=n+m;i++){
		flag[i]=INF;
	}
	q.push({qd,0,0});
	while(q.size()){
		node k=q.front();
		q.pop();
		for(int v:g[k.no]){
			if(k.no<=m&&v>m){
				int p=k.ti+t[k.no][v];
				if(p>flag[v]) continue;
				flag[v]=p;
				q.push({v,p,1});
			}else{
				int p=k.ti;
				if(k.la) p+=t[k.no][v];
				if(p>flag[v]) continue;
				flag[v]=p;
				q.push({v,p,0});
			}
		}
	}
	cout<<flag[zd]+w[qd]+w[zd]<<"\n";
	return;
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int tt;
			cin>>a[i][j]>>tt;
			t[a[i][j]][i+m]=t[i+m][a[i][j]]=tt;
			g[a[i][j]].push_back(m+i);
			g[m+i].push_back(a[i][j]);
		}
	}
	for(int i=1;i<=q;i++){
		int aa,bb;
		cin>>aa>>bb;
		bfs(aa,bb);
	}
	return 0;
} 

