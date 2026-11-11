#include<bits/stdc++.h>
using namespace std;
struct Edge{
	int to;
	long long val;
};

vector<vector<Edge>> s(500005);
vector<vector<Edge>> sp(500005);

int fa[500005];
int kval[500005];

int find(int x){
	if(x == fa[x]){
		return x;
	}
	
	return find(fa[x]);
}

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	for(int i = 0;i < m;i++){
		cin >> kval[i];
	}
	int p = 0;
	for(int j = 0;j < n;j++){
		int a;
		cin >> a;
		s.push_back(s[0]);
		for(int k = 0;k < a;k++){
			Edge ai;
			int temp;
			cin >> temp;
			ai.to = j;
			cin >> ai.val;
			s[temp].push_back(ai);
		}
	}
	
	for(int i = 0;i < m;i++){
		for(int j )
		sp[s[i][0]].push_back(s[i]);
	}
	
	for(int T = 0;T < q;T++){
		int x,y;
		cin >> x >> y;
		
	}
	
	
	return 0;
}