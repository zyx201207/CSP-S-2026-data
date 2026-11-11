#include<bits/stdc++.h>
using namespace std;
//bool b_1;
int c,n,m,d,q;
const int N = 5e5+10;
int w[N],k[510],a[510][N],t[510][20010];
int f_sta,s_sta;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++) cin >> w[i];
	for(int i = 1;i <= n;i++){
		cin >> k[i];
		for(int j = 1;j <= k[i];j++){
			cin >> a[i][j]>>t[i][j];
		} 
	}
	while(q--){
		
		cin >> f_sta >> s_sta;
		
		int ans = w[f_sta]+w[s_sta]+t[1][f_sta]+t[1][s_sta];
		cout << ans <<endl;
	}
	return 0;
}
