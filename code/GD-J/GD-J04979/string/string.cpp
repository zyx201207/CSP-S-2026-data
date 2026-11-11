#include<bits/stdc++.h>
using namespace std;
const int N = 2 * 1e5 + 5;
struct node{
	int n;
	char c;
};

node a[N];
int n;
long long ans = 0;

int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		scanf("%lld %c", &a[i].n, &a[i].c);
	}
	int l = 1, r = n;
	while(l < r){
		bool t = a[l].c != a[r].c;
		if(a[l].n < a[r].n){
			a[r].n -= a[l].n;
			ans += t * a[l].n;
			l++;
		}else if(a[l].n > a[r].n){
			a[l].n -= a[r].n;
			ans += t * a[r].n;
			r--;
		}else{
			ans += t * a[l].n;
			l++;
			r--;
		}
	}
	cout << ans;
	return 0;
} 
