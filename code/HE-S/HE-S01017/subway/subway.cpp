#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct subway{
	vector<int> to;
	vector<int> ti;
};
struct qe{
	ll arr,used;
};
vector<int> w;
vector<subway> sub;
ll bfs(int t,int s){
	vector<bool> use;
	use.push_back(true);
	for(int i=0;i<w.size();i++) use.push_back(false);
	ll ans=w[t]+w[s],i,j;
	ll est=LLONG_MAX;
	queue<qe> q;
	qe aaa;
	aaa.arr=t,aaa.used=0;
	q.push(aaa);
	while(!q.empty()){
		qe h=q.front();
		q.pop();
		if(use[h.arr]) continue;
		use[h.arr]=true;
		if(h.arr==s){
			est=min(est,h.used);
			if(est<0) est=2147483649;
			continue;
		}
		for(i=0;i<sub.size();i++){
			bool f=false;
			ll pos;
			for(j=0;j<sub[i].to.size();j++){
				if(sub[i].to[j]==h.arr){
					f=true;
					pos=j;
					break;
				}
			}
			if(!f) continue;
			for(j=0;j<sub[i].to.size();j++){
				if(sub[i].to[j]!=h.arr&&use[sub[i].to[j]]==false){
					qe nw;
					nw.arr=sub[i].to[j];
					nw.used=sub[i].ti[j]+sub[i].ti[pos]+h.used;
					q.push(nw);
				}
			}
		}
	}
	return est+ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q,i,j,h;
	cin>>c>>n>>m>>d>>q;
	w.push_back(0);
	for(i=1;i<=m;i++){
		int x;
		cin>>x;
		w.push_back(x);
	}
	for(i=1;i<=n;i++){
		int k;
		cin>>k;
		subway oi;
		for(j=1;j<=k;j++){
			int aij,tij;
			cin>>aij>>tij;
			oi.to.push_back(aij);
			oi.ti.push_back(tij);
		}
		sub.push_back(oi);
	}
	while(q--){
		int x,y;
		cin>>x>>y;
		cout<<bfs(x,y)<<"\n";
	}
	return 0;
}
