#include <bits/stdc++.h>
using namespace std;
int a[100005];
int sum[100005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	int sum=0;
	for(int i =1; i <= n; i++){
		sum++;
		cout << sum << " ";
	}
	return 0;
}
