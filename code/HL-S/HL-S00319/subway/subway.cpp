#include<bits/stdc++.h>
using namespace std;

struct node{
	int line;
	int trans;
};
void build(vector<node> lines,vector<vector<int>>& edge){
	
}


int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
	int c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	vector<int> lth1(m);
	for(int i=0;i<m;i++){
		cin>>lth1[i];
	}
	vector<node> lines;
	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		for(int j=0;j<k;j++){
			int a,t;
			cin>>a>>t;
			lines.push_back({a,t});		
		}
	}
	vector<vector<int>> edges(m);
	build(lines,edges)
	for(int i=0;i<q;i++){
		int x,y;
		cin>>x>>y;
		solve(edges,x,y);
	}
	

    return 0;
}


