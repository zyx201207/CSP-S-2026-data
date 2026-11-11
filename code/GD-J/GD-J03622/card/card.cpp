#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<stack>
using namespace std;

#define N 500010

int n, m;
int a[N];
int ans[N];
stack<int>g;
bool st[N];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("card.in","r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n; i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n; i++){
		memset(st ,false ,sizeof st);
		while(!g.empty())g.pop();
		for(int j = i;j <= n; j++){
			
			if(st[a[j]]){
				int t = 0;
				while(t != a[j]){
					t = g.top();
					g.pop();
				}
			}
			
			st[a[j]] = true;
			g.push(a[j]);
		}
		while(!g.empty()){
			int h = g.top();
			ans[h] ++;
//			cout << h << " ";
			g.pop();
		}
//		cout << "\n";
	}
	for(int i = 1;i <= m; i++){
		cout << ans[i] << " ";
	}
	return 0;
}

