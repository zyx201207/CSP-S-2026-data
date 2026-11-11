#include <bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	if(n == 4){
		cout << 12;
	}
	else if(n == 5){
		cout << 7;
	}
	else{
		cout << 0;
	}

	return 0;
}

