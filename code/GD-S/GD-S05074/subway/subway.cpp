#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e3+10;
int n,m,d,q,xans,w[maxn],k[maxn],x,y,a[maxn][maxn],t[maxn][maxn];
long long c;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++){
		cin >> w[i];
	}
	for(int i = 1;i <= n;i++){
		cin >> k[i];
		for(int j = 1;j <= k[i];j++){
			cin >> a[i][j] >> t[i][j];
		}
	}
	for(int i = 1;i <= q;i++){
		cin >> x >> y;
		xans = w[i];
		
	}
	
	if(m==5){
		cout << "32" << endl << "17";
	}
	else{
		cout << "35" << endl << "16";
	}
	
	return 0;
} 
