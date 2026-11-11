#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
using LL = long long;
const int N = 200005;
struct node{
	LL a;
	char c;
};
node a[N];
LL n, tot, len;
void inpt(){
	cin >> n;
	for(LL i=0; i<n; i++){
		cin >>a[i].a >>a[i].c;
		len += a[i].a;
	}
	return;
}
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	inpt();
	int l=0, r = n-1, fns = 0;
	while(l<r){
		if(a[l].a < a[r].a){
			tot += (a[l].c != a[r].c) * a[l].a;
			a[r].a -= a[l].a;
			l++;
		}
		else if(a[l].a > a[r].a){
			tot += (a[l].c != a[r].c) * a[r].a;
			a[l].a -= a[r].a;
			r--;
		}
		else{
			tot += (a[l].c != a[r].c) * a[r].a;
			a[l].a = 0;
			a[r].a = 0;
			l++;
			r--;
		}
	}
	cout << tot;
	return 0;
}
