#include<bits/stdc++.h>
using namespace std;
const int A = 2e5 + 10;
int n;
bool flag;
long long ans;
struct{
	long long a;
	char c;
}h[A];
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> h[i].a >> h[i].c;
		if(i >= 2 && h[i].c != h[i - 1].c){
			flag = true;
		}
		ans += h[i].a;
	}
	if(!flag){
		cout << 0;
		return 0;
	}
	cout << ans / 2;
	
	return 0;
} 
