#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,p;
struct s1{
	vector<pair<int,int>> v;
	int t;
};
struct s2{
	vector<int> v;
	int q;
};
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >>c>>n>>m>>d>>p;
	vector<vector<int>> tm[m][m];
	int w[m];
	for(int i;i<m;i++)cin>>w[i];
	s1 s[m];
	s2 ss[n];
	for(int i=0;i<n;i++){
	cin >> ss[i].q;
		for(int j=0;j<ss[i].q;i++){
			int u,t;
			cin >> u >> t;
			ss[i].v.push_back(u);
			pair<int,int> po;
			po.first=u;
			po.second=t;
			s[u].v.push_back(po);
		}
	}
	for(int i=0;i<p;i++){
		int x,y;
		cin>> x >> y;
		cout << s[x].t+s[y].t << endl;
	}
	return 0;
}
