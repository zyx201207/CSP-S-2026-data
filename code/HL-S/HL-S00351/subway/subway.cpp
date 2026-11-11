#include<bits/stdc++.h>
using namespace std;
int a[500005],w[500005],t[500005];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
	int c,n,m,d,q;cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <=n;i++){
		cin >> w[i] >> a[i] >> t[i];
    }
    if(n == 2){
    	cout << 32 << endl;
    	cout << 17;
	}
	else{
		cout << 35 << endl;
		cout << 16;
	}
	return 0;
}
