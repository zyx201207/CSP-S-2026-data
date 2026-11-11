#include<bits/stdc++.h>
using namespace std;
using ll= long long;
bool usedpr[500005];
bool usedeg[505];
int topr[500005];
vector<int> pr[500005];
vector<int> eg[505];
vector<int> prw[500005];
vector<int> egw[505];
ll mi=0x3f3f3f3f3f3f3f3f;
int ove;
void dfs(int now,ll w){//进前 usedpr【开始 】=1; 
	if(now==ove){
		mi=min(mi,w);
		return;
	}
	for(int i=0;i<(int)pr[now].size();i++){
		int neg=pr[now][i],weg=prw[now][i];
		if(usedeg[neg])continue;
		usedeg[neg]=1;
		for(int j=0;j<(int)eg[neg].size();j++){
			int nep=eg[neg][j],wep=egw[neg][j];
			if(usedpr[nep])continue;
			usedpr[nep]=1;
			dfs(nep,w+weg+wep);
			usedpr[nep]=0;
		}
		usedeg[neg]=0;
	} 
	return;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int art,n,m,d,q;
	cin>>art>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>topr[i]; 
	for(int i=1;i<=n;i++){
		int op;
		cin>>op;
		for(int j=1;j<=op;j++){
			int h,w;
			cin>>h>>w;
			pr[h].push_back(i);
			prw[h].push_back(w);
			eg[i].push_back(h);
			egw[i].push_back(w);
		}
	}
	for(int i=1;i<=q;i++){
		int g,h;
		cin>>g>>h;
		ove=h;
		mi=0x3f3f3f3f3f3f3f3f;
		usedpr[g]=1;
		dfs(g,0);
		cout<<mi+topr[g]+topr[h]<<'\n';
	} 
	return 0;
}
