#include<bits/stdc++.h>
using namespace std;

unsigned long long n, a[10000000], m;
bool cmp(unsigned long long a, unsigned long long b){
	a < b;
}
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (unsigned long long i = 0; i < n; i++){
		cin >> a[i];
	}
	sort (a, a + n, cmp);
	cout << a[0];
	return 0;
    fclose(stdin);
    fclose(stdout);
}
