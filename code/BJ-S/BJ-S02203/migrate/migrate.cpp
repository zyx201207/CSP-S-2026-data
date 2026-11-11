//Brude Force-DFS
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int N = 1e3+5;
bool vis[N];
long long a[N],d;
int n,m;
int b[N][N],c[N][N];//b:length;c:count
int e[N],sum = 0;
void dfs(vector<int>u,int v,int cnt) {/*
	for (int i = 0;i < u.size();i++) {
		cout << u[i] << ' ';
	}
	cout << endl << v << ' ' << cnt << endl;
	cout << endl;*/
	vis[v] = 1;
	//u != v
	for (int i = 0;i < u.size();i++) {
		if (b[u[i]][v] > cnt - i) {
			b[u[i]][v] = cnt - i;
			c[u[i]][v] = 1;
		}else if (b[u[i]][v] == cnt - i) {
			c[u[i]][v]++;
		}/*
	for (int i = 0;i < u.size();i++) {
		cout << u[i] << ' ';
	}
	cout << endl;
		cout << u[u.size() - 1] << endl;
		cout << u[i] << ' ' << v << endl;
		cout << b[u[i]][v] << ' ' 
		<< c[u[i]][v] << endl << endl;*/
	}/*
	if (u.size()) {
	cout << u[u.size() - 1] << ' ' << v << endl;
	cout << b[u[u.size() - 1]][v] << ' ' << c[u[u.size() - 1]][v] << endl << endl;}*/
	cnt++;
	for (int i = v + 1;i <= n;i++) {
		if (a[i] - a[v] > d) {/*
			cout << i << ' ' << v << endl;
			cout << a[i] << ' ' << a[v] << endl;
			cout << "Bye!" << endl;*/
			return;
		}
		if (!vis[i]) {/*
			cout << "from:" << endl;
			for (int i = 0;i < u.size();i++) {
				cout << u[i] << ' ';
			}
			cout << endl << v << ' ' << cnt << endl;
			cout << "to:" << endl;*/
			u.push_back(v);
			dfs(u,i,cnt);
			u.pop_back();
		}
	}
	vis[v] = 0;
}
int T,Q;
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> T >> Q;
	while (Q--) {
		sum = 0;
		memset(vis,0,sizeof(vis));
		memset(b,0x3f,sizeof(b));
		memset(c,0,sizeof(c));
		cin >> n >> d;
		cin >> a[0];
		b[0][0] = 0;
		for (int i = 1;i < n;i++) {
			cin >> a[i];
			b[i][i] = 0;
			a[i] -= a[0];
		}
		a[0] = 0;/*
		for (int i = 0;i < n;i++) {
			cout << a[i] << ' ';
		}
		cout << endl;*/
		vector<int>INIT;
		//INIT.push_back(1);
		/*
		for (int i = 0;i < n;i++) {
			dfs(INIT,i,0);
		}*/
			dfs(INIT,0,0);/*
		for (int i = 0;i < n;i++) {
			for (int j = 0;j < n;j++) {
				if (b[i][j] < 100)
				cout << b[i][j] << " ";
				else
				cout << "  ";
			}
			cout << endl;
		}
			cout << endl;*/
		for (int i = 0;i < n;i++) {
			for (int j = 0;j < n;j++) {
				//cout << c[i][j] << ' ';
				if (c[i][j] == 2) {
					sum++;
				}
			}
			//cout << endl;
		}
		cout << sum / 2 << endl;
		//cout << endl;
	}
			
	return 0;
}