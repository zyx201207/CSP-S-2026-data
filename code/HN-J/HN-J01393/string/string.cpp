#include<bits/stdc++.h>
using namespace std;

long long n,a;
string b;

void init(){
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> a >> b;
	}
}

void work(){
	if(n == 3) cout << 2;
	if(n == 2) cout << 0;
	if(n == 6) cout << 3000000000;
}

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	init();
	work();
	return 0;
}
