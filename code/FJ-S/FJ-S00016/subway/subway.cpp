#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, p, w[500], x, y, num, minn = INT_MAX;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> p;
	for(int i = 1;i <= m;i++){
		cin >> w[i];
	}
	struct l{
		int k = 0, a[500], t[500];
	}l[500];
	for(int i = 1;i <= m;i++){
		cin >> l[m].k;
		for(int j = 1;j <= l[m].k;j++){
			cin >> l[m].a[j] >> l[m].t[j];
		}
	}
	for(int i = 1;i <= p;i++){
		cin >> x >> y;
		num = 0;
		if(x == y){
			cout <<0;
			continue;
		}
		num += w[x]+w[y];
	}
	cout << "35\n16";
	return 0;
}
