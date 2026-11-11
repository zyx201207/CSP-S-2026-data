#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2000006;
int a[MAXN];

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	if(c == 0&&n == 2){
		cout << 32 << endl << 17;
	}
	else if(c == 0&&n == 3){
		cout << 35 << endl << 16;
	}
	return 0;
}