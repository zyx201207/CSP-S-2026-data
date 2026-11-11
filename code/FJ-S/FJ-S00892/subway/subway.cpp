#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,k,tmp1,ans=0x3ffffff,tmp2;
vector<int> w;
vector<vector<int>> subroute;
vector<map<int,int>> transt;
struct place{
	int t;
	int line;
	int station;
};
void bfs(int from,int ends,int depth){
	queue<place> planTogo;
	vector<int> record;
	record.resize(m+2,0x3ffffff);
	int dep=0;
    for(auto i:transt[from]){
    	planTogo.push({w[from]+i.second,i.first,from});
	}
	while(!planTogo.empty() && (dep<=depth)){
		place sta=planTogo.front();
		planTogo.pop();
		if(sta.station==ends) {
			ans=min(ans,sta.t+w[ends]+transt[sta.station][sta.line]);
		}
		for(int i:subroute[sta.line]){
			if((i==ends || !transt[i].empty())&&record[i]>sta.t) {
				planTogo.push({sta.t,sta.line,i});
				record[i]=sta.t;
			}
		}
		place a;
		for(pair<int,int> i:transt[sta.station]){
			if(i.first==sta.line) continue;
			a.station=sta.station;
			a.line=i.first;
			a.t=sta.t+i.second+transt[sta.station][sta.line];
			planTogo.push(a);
		}
		dep++;
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.sync_with_stdio(false);
	cin>>c>>n>>m>>d>>q;
	w.resize(m+2);
	subroute.resize(n+2);
	transt.resize(m+2);
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++){
		cin>>k;
		subroute[i].resize(k);
		for(int j=0;j<k;j++) {
			cin>>subroute[i][j]>>tmp1;
			transt[subroute[i][j]][i]=tmp1;
		}
	}
	for(int f=0;f<q;f++) {
		cin>>tmp1>>tmp2;
		bfs(tmp1,tmp2,n*d*abs(tmp1-tmp2)/3);
		cout<<ans<<endl;
		ans=0x3ffffff;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
