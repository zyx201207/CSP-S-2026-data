#include<bits/stdc++.h>

using namespace std;

int n,m;
const int N = 2e5 + 5;
long long a[N];

int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a + 1,a + 1 + n);
	if(m == 1){
		cout << a[n];
	}else{
		cout << a[n + 1 - m];
	}
	return 0;
}