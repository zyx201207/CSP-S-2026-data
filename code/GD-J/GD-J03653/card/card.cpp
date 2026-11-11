#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5 + 10;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n,m;
	string a[10005];
	cin>>n>>m;
	for(int i=0;i<=n-1;i++){
		cin>>a[i];
	}
	for(int i=0;i<=m-1;i++){
		cout<<a[i];
	}
	return 0;
}
