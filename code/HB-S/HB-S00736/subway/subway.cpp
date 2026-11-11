#include<bits/stdc++.h>
using namespace std;
const int man=5e5+10;
struct zuo{
	int dian;
	int quan;
};
vector<zuo> che[510];
vector<int> zhan[man];
long long ans=1e12;
long long a[510][510]={};
int dfs(int di,int qi,int mo,long long time){
	if(a[di][mo]!=0){
		ans=min(ans,time+a[di][mo]);
		a[qi][mo]=ans;
		return ans;
	}
	if(di==mo){
		ans=min(ans,time);
		a[qi][mo]=ans;
		return ans;
	}
	for(int i=0;i<zhan[di].size();i++){
		for(int j=0;j<che[zhan[di][i]].size();j++){
			if(che[zhan[di][i]][j].dian!=di){
				dfs(che[zhan[di][i]][j].dian,qi,mo,time+che[zhan[di][i]][j].quan);
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	int w[510];
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		for(int j=1;j<=k;j++){
			int x,y;
			cin>>x>>y;
			che[i].push_back({x,y});
			zhan[x].push_back(i);
		}
	}
	for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		cout<<dfs(x,x,y,w[x]+w[y])<<endl;
	}
	return 0;
}
