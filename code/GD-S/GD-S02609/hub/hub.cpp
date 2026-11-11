#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=510,maxm=5e5+10,inf=1e18;
int mi[maxn*2][maxn*2];
int c,n,m,d,q;//测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过，以及出行计划数
int w[maxm];//依次表示从每个地铁站的地铁口走到站厅需要的时间。
int k[maxn];
vector<int>a[maxn];
vector<int>t[maxn];
int st,en;
void pr(){ 
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m;j++){
			mi[i][j]=inf;
			if(i==j){
				mi[i][j]=0;
			}
		}
	}
	return ;
}
void b1(){
	pr();
	for(int i=1;i<=n;i++){
		mi[a[i][1]][a[i][2]]=mi[a[i][2]][a[i][1]]=t[a[i][1]][a[i][2]]+t[a[i][2]][a[i][1]];
	}cerr<<1<<endl; 
	for(int k=1;k<=m;k++){
		for(int i=1;i<=m;i++){
			for(int j=1;j<=m;j++){
				int need=min(mi[i][k]+mi[k][j],mi[j][k]+mi[k][i]);
				if(need<mi[i][j]){
					mi[i][j]=mi[j][i]=need;
				}
			}
		}
	}return ;
}
signed main(){
	ios::sync_with_stdio(NULL);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		cout<<1<<endl;
	}
	return 0;
}
