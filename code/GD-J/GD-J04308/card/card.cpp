#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;
const int N = 5e5+10,M = 3e5+10;
int a[N],sum[M];
bool vis[M];
stack <int> s;
void dl(int x){
	while (s.top() != x){
		s.pop();
	}
}
int main() {
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for (int i = 1;i <= n;i++){
		fill(vis+1,vis+m+1,false);
		for (int j = i;j <= n;j++){
			if (!vis[a[j]])s.push(a[j]);
			else {
				dl(a[j]);
			}
			vis[a[j]] = true;
		}
		while (!s.empty()){
			sum[s.top()]++;
			s.pop();
		}
		
	}
	for (int i = 1;i <= m;i++){
		cout << sum[i] << " ";
	}
	return 0;
}
