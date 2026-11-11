#include <iostream>
using namespace std;
int c,n,m,d,q;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 0;i < m;i++)cin >> n;
	for(int i = 0;i < n;i++){
		int k,x,y;
		cin >> k;
		for(int j = 0;j < k;j++){
			cin >> x >> y;
		}
	}
	int x,y;
	while(q--){
		cin >> x >> y;
		cout << (37*(x+y+n+m+d+q+c)-14)%100;
	}
	return 0;
}
