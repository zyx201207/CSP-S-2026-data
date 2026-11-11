#include <bits/stdc++.h>
using namespace std;
int n,m,a[500009],book[500009];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			book[j]++;
		}
	}
	for(int i=1;i<=n;i++){
		cout << book[i]<< ' ';
	}
	return 0;
}
