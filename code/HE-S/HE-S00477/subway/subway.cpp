#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,x,y;
int w[500005]={0};
bool u[500005]={0};
struct edge{
	vector<int> a,t;
}e[500];
struct station{
	vector<int> ed;
}s[500005];
int f(int flag,int v,int t){
}
void dfs(int nows,int nowe,int flag,int used){//所在车站，所在线，状态，已步行时间 
	if(nows==y){
		if(flag==3){
			used+=e[nowe].t[f(2,nowe,nows)];
		}
	}
	return ;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout); 
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	int k,zhan,shi;
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			cin>>zhan>>shi;
			e[k].a.push_back(zhan);
			e[k].t.push_back(shi);
			s[zhan].ed.push_back(k);
		} 
	}
	while(q--){
		cin>>x>>y;
		//cout<<x<<" "<<y<<endl;
		dfs(x,-1,2,w[x]);//1表示地铁口，2表示站厅，3表示站台 
		cout<<ans<<endl;
	}
	//未完待续点点点 
	return 0;
}
