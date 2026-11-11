#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n,m,a[200005];
	cin >> n >> m;
	for(long long i = 0;i < n;i++){
		cin >> a[i];
	}
	for(long long i = 1;i <= m;i++){
		if(a[n - 1] == i){
			cout << n << " ";
		}else{
			cout << "0 ";
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
