#include <bits/stdc++.h>
#define PII pair<int,int> 
using namespace std;
long long c,n,m,d,q,w[500005],k,s1,s2;
vector<int>a[505],t[505];
priority_queue<vector<PII>,PII,greater<PII> > pq;
int bfs(){
	while(!pq.empty()){
		pq.pop();
	}
	pq.push(0);
	while(!pq.empty()){
		int x=pq.top().first,y=pq.top().second;
		pq.pop();
		if(y==s2){
			return x;
		}
		for(int i=1;i<=n;i++){
			int at;
			for(int j=0;j<a[i].size();j++){
				if(a[i][j]==y){
					at=t[i][j];
					break;
				}
			}
			for(int j=0;j<a[i].size();j++){
				pq.push({x+t[i][j]+at,a[i][j]});
			}
		}
	}
	return 0;
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++){
		cin>>w[i];
	}
	for(int i=1;i<=n;i++){
		cin>>k;
		for(int j=1;j<=k;j++){
			long long aa,tt;
			cin>>aa>>tt;
			a[i].push_back(aa);
			t[i].push_back(tt);
		}
	}
	for(int i=1;i<=q;i++){
		cin>>s1>>s2;
		cout<<bfs()+w[s1]+w[s2]<<endl;
	}
	return 0;
}
