#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N = 5e5+5;
int a[N],n,m;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		int x;
		cin >> x;
		a[x]++;
	}for(int i = 1;i <= m;i++){
		cout << a[i]%2;
	}fclose(stdin);
	fclose(stdout);
	return 0;
}
