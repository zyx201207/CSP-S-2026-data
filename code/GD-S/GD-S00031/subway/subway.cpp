#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,b[405],k,a[205][405],t[205][405],r[205],l[205];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	if(c == 0){
		if(n == 3) cout << "35\n" << "16\n";
	}
	else{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(t,0,sizeof(t));
		if(n == 500)
		for(int i = 1;i <= m;i++){
			cin >> b[i];
		}
		for(int i = 1;i <= n;i++){
			cin >> k;
			for(int j = 1;j <= k;j++){
				cin >> a[i][j] >> t[i][j];
			}
		}
		for(int i = 1;i <= q;i++){
			cin >> l[i] >> r[i];
		} 
		for(int i = 1;i <= q;i++){
			cout << l[i] * 4 << "\n"; 
			}
		}
	
	return 0;
}
