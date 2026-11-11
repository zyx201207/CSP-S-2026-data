#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
#define INF 0x3f3f3f3f
using pii = pair<int,int> ;
int c,m,n,d1,q,w[500100];
vector<pii>v[500100],s[500100],ans;
int d[500100];
bool st[500100];
void di(int x){
	memset(st,false,sizeof st);
	memset(d,INF,sizeof d);
	priority_queue<pii,vector<pii>,greater<> >q;
	q.push({0,x});
	d[x]=0;
	while(q.size()){
		auto f=q.top();
		q.pop();
		int b=f.second;
		if(st[b])continue;
		st[b]=1;
		for(auto i:v[b]){
			if(d[i.first]>d[b]+i.second){
				d[i.first]=d[b]+i.second;
				q.push({d[i.first],i.first}); 
			}
		}
	}
}
bool cmp(pii a,pii b){
	return a.second>b.second;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>d1>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		vector<pii>a;
		for(int j=1;j<=k;j++){
			int x,t;
			cin>>x>>t;
			if(a.size()==0){
				a.push_back({x,t});
				continue;
			}
			for(auto i:a){
				v[i.first].push_back({x,t+i.second});
				v[x].push_back({i.first,t+i.second});
			}
			a.push_back({x,t});
		}
	}
	while(q--){
		int l,r;
		cin>>l>>r;
		if(s[l].size())s[l].push_back({r,q});
		else s[r].push_back({l,q});
	}
	for(int i=1;i<=m;i++){
		if(!s[i].size())continue;
		di(i);
		for(auto j:s[i]){
			ans.push_back({w[i]+w[j.first]+d[j.first],j.second});
		}
	}
	sort(ans.begin(),ans.end(),cmp);
	for(auto i:ans){
		cout<<i.first<<endl;
	}
	return 0;
}
/*
0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
