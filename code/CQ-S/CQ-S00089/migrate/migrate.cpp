#include<bits/stdc++.h>
using namespace std;
int n,c,T,dd,ans;
const int N=2e6+5;
int x[N];
struct edge{
	int u,v;
	long long w;
};
int d[N];
vector<edge> t[N];
int op[N];
int work(int xx){
	int cnt=0;
	queue<int> q;
	memset(d,0x3f3f3f,sizeof(d));
	memset(op,0,sizeof(op));
	d[xx]=0;
	q.push(xx);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		int r=t[u].size();
		for(int i=0;i<r;i++){
			int v=t[u][i].v;
			if(v<u)continue ;
			if(d[u]+1==d[v])
				if(op[v]) cnt--,op[v]++;
				else cnt++,op[v]++;
			if(d[u]+1<d[v]){
				q.push(v);
				d[v]=d[u]+1;
			}
			
		}
	}
	return cnt;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",sdtout);
	cin>>c>>T;
	while(T--){
		ans=0;
		memset(t,0,sizeof(t));
		cin>>n>>dd;
		cin>>x[1];
		for(int l=1,i=2;i<=n;i++){
			cin>>x[i];
			while(x[i]-x[l]>dd)l++;
			for(int j=l;j<i;j++){
				t[j].push_back({j,i,1});
				t[i].push_back({i,j,1});
			}
		}
		for(int i=1;i<=n;i++)
			ans+=work(i);
		cout<<ans<<endl;
	}
	return 0;
}
