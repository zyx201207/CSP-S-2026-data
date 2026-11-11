#include<bits/stdc++.h>
using namespace std;
struct dot{
	int t;
	int w;
};
int maxn = 500005;
int inf = 0x3f3f3f3f;
vector<dot> k[500005];
bool usd[500005];
int ans=inf;
void dfs(int now,int val,int f){
	if(now == f){
		ans = min(ans,val);
		return;
	}
	for(int i=0;i<k[now].size();i++){
		int v = k[now][i].t;
		int w = k[now][i].w;
		if(!usd[v]) {
			usd[v] = 1;
			dfs(v,val+w,f);
			usd[v] = 0;
		}
		
	}
} 
//既然坐地铁不用时间，那么只要把站台连起来就行了
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,n,m,d,q;cin>>c>>n>>m>>d>>q;
	int w[m+5];
	vector<int> a[m+5];
	vector<int> t[m+5];
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=0;i<n;i++){
		int tp;cin>>tp;
		for(int j=0;j<tp;j++){
			int t1,t2;
			cin>>t1>>t2;
			a[i].push_back(t1);
			t[i].push_back(t2);
		}
	}
	int marth7[q][2];
	for(int i=0;i<q;i++){
		cin>>marth7[i][0]>>marth7[i][1];
	}
	//建图；
	for(int i=0;i<m;i++){
		for(int j=0;i<a[i].size();i++){
			for(int p=j+1;p<a[i].size();p++){
				int u = a[i][j],v = a[i][p];
				//cout<<"now_p:"<<u<<" push:"<<v<<" t[i][j]"<<t[i][j]<<" t[i][p]:"<<t[i][p]<<endl;
				k[u].push_back({v,t[i][j]+t[i][p]});
				k[a[i][p]].push_back({a[i][j],t[i][j]+t[i][p]});
			}
		}
	}
	//跑dij...但是忘了
	//最朴素的DFS吧 
	for(int rst=0;rst<q;rst++){
		ans = inf;
		for(int i=0;i<m+5;i++) usd[i] = 0;
		
		dfs(marth7[rst][0],0,marth7[rst][1]);
		//cout<<"ws:"<<w[marth7[rst][0]]<<" wf"<<w[marth7[rst][1]]<<endl;
		cout<<ans+w[marth7[rst][0]]+w[marth7[rst][1]]<<endl;
	} 
	return 0;
}
