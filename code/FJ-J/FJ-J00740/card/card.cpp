#include<iostream>
#include<cstring>
#include<stack>
using namespace std;
const int N = 500005;
const int M = 300005;
int n,m;
int tot;
int a[M];
int s[M];
bool c[M];
void solve(int x) {
	stack<int> p;
	memset(c,0,sizeof(c));
	for (int i=x; i<=n; i++) {
		if (!c[a[i]]) {
			p.push(a[i]);
			c[a[i]]=true;
			s[a[i]]++;
		} else {
			while (p.top()!=a[i]) {
				s[p.top()]--;
				c[p.top()]=false;
				p.pop();
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	cin>>n>>m;
	for (int i=1; i<=n; i++)
		cin>>a[i];
	for (int i=1; i<=n; i++) {
		solve(i);
	}
	for (int i=1; i<=m; i++)
		cout<<s[i]<<' ';
	return 0;
}
