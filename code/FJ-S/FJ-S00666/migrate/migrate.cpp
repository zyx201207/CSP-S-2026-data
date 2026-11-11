#include <bits/stdc++.h>
using namespace std;
int c,t,x[2000008];
vector<int> mp[2000008];
struct stu{
	int id,step;
};
bool bj[1000008];
int bfs(int be){
	int si=0;
	queue<stu> p;
	stu w,r,g;
	w.id=be;
	w.step=0;
	bj[w.id]=true;
	p.push(w);
	while(!p.empty()){
		r=p.front();
		p.pop();
		for(int i=0;i<mp[r.id].size();i++){
			g.id=mp[r.id][i];
			g.step=r.step+1;
			if(bj[mp[g.id][i]]==true){
				si++;
				continue;
			}
			bj[mp[g.id][i]]=true;
			p.push(g);
		}
	}
	return si;
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>c>>t;
	while(t--){
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>x[i];
		}
		sort(x+1,x+1+n);
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(x[i]-d<=x[j]&&x[j]<=x[i]+d){
					mp[i].push_back(j);
				}
			}
		}
		int sum=0;
		for(int i=1;i<=n;i++){
			int ans=bfs(i);
			sum+=ans;
		}
		cout<<sum;
	}
	return 0;
} 
