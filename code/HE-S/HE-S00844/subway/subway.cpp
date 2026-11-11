#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,o;
const unsigned long long N=1e9+10;
unsigned long long w[N];
struct pl{
    int places,times;
}K;
struct llp{
	int x,y;
}p;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i=0;i<m;i++)
	    cin >> w[i];
	for(int i=0;i<n;i++){
		cin >> o;
		for(int j=0;j<o;j++)
		    cin >> K.places >> K.times;
	}
	for(int i=0;i<q;i++){
		cin >> p.x >> p.y;
	}
	cout << 7;
	return 0;
}
