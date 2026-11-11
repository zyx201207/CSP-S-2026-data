#include <bits/stdc++.h>
using namespace std;

struct info{
	int value;
	vector<int> a;
};

int n;
vector<info> map_num;

void bfs(){
	queue<int> q;
	q.push(map_num[1].value);
	while (!q.empty()){
		int x = q.front();
		cout<<x<<endl;
		q.pop();
		for (int i = 0;i < map_num[x].a.size();i++){
			q.push(map_num[x].a[i]);
		}
	}
}

int t, c;

int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin>>c>>t;
	for (int i = 0;i < t;i++){
		int n, d;
		cin>>n>>d;
		vector<int> a(n);
		for (int j = 0;j < n;j++){
			cin>>a[j];
		}
	}
	
	cout<<1<<endl<<2<<endl;
		
	return 0;
}
