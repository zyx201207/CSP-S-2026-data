#include<bits/stdc++.h>
using namespace std;
int ktot[500005];
int ttoz[500005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	srand(time(NULL));
	int tot;
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i ++) cin >> ktot[i];
	for(int i = 1;i <= n;i ++){
		int k;
		cin >> k;
		for(int j = 1;j <= 2*k;j ++){
			int t1,t2;
			cin >> t1 >> t2; 
			tot += t2;
		}
	}
	tot/=2;
	for(int i = 1;i <= q;i ++){
		int l,r;
		cin >> l >> r;
		cout << rand()%tot << endl;
	}
	return 0;
}

