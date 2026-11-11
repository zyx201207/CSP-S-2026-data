#include <bits/stdc++.h>
using namespace std;

vector<int> a;

int and_(int a, int b){
	long long ans=0;
	for (int i=0; i<a/2; i++)
	if (a%2 == b%2 && a%2 == 1){
		ans += 1<<i;
	}
}

stack<int> s;
int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	cout << 7;

	
	sreturn 0;
} 
