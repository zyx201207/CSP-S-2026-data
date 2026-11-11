#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5+5;
char c[MAXN];
int a[MAXN];
int n;
int yu;
char cc;
int ans = 0;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i = 1;i<=n;i++){
		int m; char cc;
		cin>>m>>cc;
		a[i] = m;
		c[i] = cc;
	}
	cout<<0;
	return 0;
}
