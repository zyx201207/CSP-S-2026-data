#include <bits/stdc++.h>
using namespace std;
const int N=1e6+3;
long long c,n,m,d,q;
long long a[N];
vector<pair<int,long long> >graph[N];
int aa,bb;
long long ans=1000000000;
long long qw=0;
void ads(int x,long long an,int as,int op,int op2){
	if(x==bb){
		ans=min(ans,an+qw);
		return ;
	}
	if(op!=-1){
		graph[op2][op].second*=-1;
	}
	for(int i=0;i<graph[x].size();i++){
		if(graph[x][i].second>=0){
		if(as==graph[x][i].second){
			ads(graph[x][i].first,an,as,i,x);
		}
		else if(as!=graph[x][i].second&&as==0){
			ads(graph[x][i].first,an+qw,graph[x][i].second,i,x);
		}
		else{
			ads(graph[x][i].first,an+qw+qw,graph[x][i].second,i,x);
		}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		int rt;
		cin>>rt;
		int ui,ui2;
		cin>>ui>>ui2;
		qw=ui2;
		for(int j=2;j<=rt;j++){
			int ui3,ui4;
			cin>>ui3>>ui4;
			graph[ui].push_back({ui3,i});
			graph[ui3].push_back({ui,i});
			ui=ui3;
		}
	}
	for(int i=1;i<=q;i++){
		cin>>aa>>bb;
		ans=1000000000;
		ads(aa,a[aa]+a[bb],0,-1,0);
		cout<<ans<<endl;
		for(int i=1;i<=m;i++){
			for(int j=0;j<graph[i].size();j++){
				if(graph[i][j].second<=0){
					graph[i][j].second*=-1;
				}
			}
		}
	}
	return 0;
}
