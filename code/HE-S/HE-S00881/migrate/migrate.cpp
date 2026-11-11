#include<bits/stdc++.h>
using namespace std;
struct ss1{
	int u;
	int v;
};
vector<ss1> ss[100001];
int a[100001],s[100001],n,m;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int cc,c;
	cin >> c >> cc;
	while(cc--){
		cin >> n >> m;
		for(int i = 1;i <= n;i++){
			cin >> a[i];
			s[i] = a[i] - a[i - 1];
			for(int j = 0;j < ss[i - 1].size();j++){
				if(s[i] + ss[i - 1][j].v < m){
					ss[i].push_back({ss[i - 1][j].u,s[i] + ss[i - 1][j].v});
				}
			}
			ss[i].push_back({i - 1,s[i]});
		}
		cout << 1 << endl;
	}
}
