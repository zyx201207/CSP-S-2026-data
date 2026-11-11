#include<bits/stdc++.h>
using namespace std;
struct node{
	vector<int> v,x;//x线路标号 
}s[20005];//s[i]第i个站的联通情况 
int c,n,m,d,q,ans=0x3f;//n地铁线路个数，m地铁站个数，q出行计划个数 
int w[20005]={0},t[505][10005]={0};//w[i]第i个地铁口到站厅的时间，t[i][j]从地铁站j的站厅到第i条线路站台的时间
int l[505][100005]={0};//l[i][j]第i条线路联通的点 
bool l_ock[20005]={0};
void solve(int u,int v,int time,int b){//b当前线路标号
	if(u==v){
		ans=min(ans,time+t[b][v]);
		return ;
	}
	if(u>v) return ;
	for(int i=0;i<s[u].v.size();i++){
		if(!l_ock[s[u].v[i]]){
			l_ock[u]=1;
			if(b==s[u].x[i]) solve(s[u].v[i],v,time,b);
			else solve(s[u].v[i],v,time+t[b][u]+t[s[u].x[i]][u],s[u].x[i]);
			l_ock[u]=0;
		}
	}
	return ;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		int k=0;
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>l[i][j];
			cin>>t[i][l[i][j]];
		}
		for(int j=1;j<=k;j++){
			for(int K=j+1;K<=k;K++){
				s[l[i][j]].v.push_back(l[i][K]);
				s[l[i][K]].v.push_back(l[i][j]);
				s[l[i][j]].x.push_back(i);
				s[l[i][K]].x.push_back(i);
			}
		}
	}
	int x,y;
	for(int i=1;i<=q;i++){
		cin>>x>>y;
		ans=0x3f;
		solve(x,y,w[x]+w[y],0);
		cout<<ans<<endl;
	}
	return 0;
} 
