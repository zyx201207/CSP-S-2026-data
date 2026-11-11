#include<bits/stdc++.h>
using namespace std;
long long a[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	long long n,m;
	cin >> n >> m;
	for(long long i = 1; i <= n; i++){
		cin >> a[i];
	}
	for(long long i = 1; i <= n; i++){
		if(a[i] != a[i - 1]){
			cout << n - i + 1 << " ";
		}
	}
	return 0;
}
