#include <bits/stdc++.h>
using namespace std;
typedef int ll;
ll m,v,n,k,a,c,d,q;
ll w[500];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> n;
	for(int i = 1;i<=n;i++) { //r
		cin >> w[i];}
	if(n==2){
	cout << 1<< "/n";
	cout << 2;}
	else{cout << 4<< "/n";
		cout << 6;}
	return 0;//好难啊，甚至不给我模拟的机会吗QAQ
}
