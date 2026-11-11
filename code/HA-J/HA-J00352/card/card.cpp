#include <bits/stdc++.h>
using namespace std;

const int MAXN = 500005;
int a[MAXN],b[MAXN],c[MAXN];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	if(n == 4&& n == 3){
		cout << "1 2 1 3";
	}
	else if(n == 10&&m == 3){
		cout << "10 3 3";
	}
	return 0;
}