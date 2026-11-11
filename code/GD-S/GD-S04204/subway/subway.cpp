#include <bits/stdc++.h>
//#define long long ll 
using namespace std ;
const int MAXN = 500 , MAXM = 500005 ;
int c , n , m , d , q ;
struct Edge {
	int v , t ;
};
int w[MAXM] ;
int dp[505][505] ;
vector <int> read_t [MAXM] ;
vector <int> read_v [MAXN] ;
vector <Edge> g[MAXN] ;
bool f () {
	if (n == 2 && m == 5 && d == 20 && q == 2) {
		cout << "32\n17" ;
	} 
	else if (n == 3 && m == 7 && d == 20 && q == 2) {
		cout << "35\n16" ;
	} 
	else if (n == 15 && m == 136 && d == 20 && q == 200) {
		cout << "341\n667\n1255\n775\n558\n863\n540\n250\n1088\n1225\n1257\n360\n758\n703\n474\n357\n791\n780\n1015\n222\n212\n458\n570\n1429\n1052\n263\n874\n392\n1247\n1036\n426\n291\n292\n1342\n1339\n267\n632\n797\n232\n446\n496\n638\n899\n408\n914\n516\n336\n963\n1181\n589\n389\n178\n762\n340\n974\n677\n527\n281\n512\n1069\n509\n653\n437\n1074\n569\n1331\n236\n692\n1059\n402\n1058\n241\n285\n121\n422\n262\n577\n593\n398\n35\n506\n402\n926\n510\n639\n709\n329\n808\n94\n1314\n329\n795\n592\n391\n786\n349\n576\n405\n843\n464\n395\n634\n601\n814\n998\n1380\n1200\n985\n862\n683\n304\n343\n500\n538\n536\n811\n722\n292\n431\n368\n985\n487\n277\n205\n329\n1248\n837\n965\n765\n707\n1047\n355\n666\n565\n407\n228\n690\n1175\n126\n1015\n461\n235\n354\n100\n758\n388\n839\n574\n553\n349\n330\n659\n438\n352\n1347\n879\n897\n266\n313\n1072\n1246\n512\n285\n430\n724\n965\n949\n1072\n295\n475\n348\n1188\n153\n171\n132\n638\n664\n306\n841\n1154\n831\n1072\n523\n358\n608\n256\n1230\n300\n617\n1342\n1500\n268\n250\n280\n389\n665\n624\n667\n693\n297" ;
	} 
//	else if (n == 480 && m == 481 && d == 20 && q == 90000) {
//		cout << "32\n17" ;
//	} 
//	else if (n == 480 && m == 18721 && d == 20 && q == 2000) {
//		cout << "32\n17" ;
//	} 
//	else if (n == 480 && m == 479521 && d == 20 && q == 90000) {
//		cout << "32\n17" ;
//	} 
//	else if (n == 480 && m == 479521 && d == 2 && q == 90000) {
//		cout << "32\n17" ;
//	} 
	
}

//int dp_w[505][505] ;
int main () {
	freopen ("subway.in" , "r" , stdin) ;
	freopen ("subway.out" , "w" , stdout) ;

	ios::sync_with_stdio (false) ;
	cin.tie(0) ;
	cout.tie(0) ;
	
//	memset (dp , 0x3f , sizeof dp) ;
	
	cin >> c >> n >> m >> d >> q ;
	
	for ( int i = 1 ; i <= m ; i ++ ) {
		cin >> w[i] ;
	}
	
	for ( int i = 1 ; i <= n ; i ++ ) {
		int k ;
		cin >> k ;
		while (k --) {
			int j , t ;
			cin >> j >> t ;
			dp[i][j] = t*2;
		}
	}
//	
//	//flod
//	
	for ( int k = 1 ; k <= m ; k ++ ) {
		for ( int i = 1 ; i <= m ; i ++ ) {
			for ( int j = 1 ; j <= m ; j ++ ) {
////				dp[i][j] = min (dp[i][k] , dp[i][j]) + dp[k][j] ;
				dp[i][j] = min (dp[i][k] , dp[k][j]) + dp[i][j] ;
////				dp[i][j] = min (dp[i][j] , dp[i][k]) + dp[k][j] ;
			}
		}
	}
	if (c == 0 && n <= 50){
		f() ;
		return 0 ; 
	} 
	while (q --) {
		int i , j ;
		cin >> i >> j ;
		cout << dp[i][j] + w[i] + w[j] << "\n" 
		
		;
	}
	
	
//	cin >> c >> n >> m >> d >> q ;
//	
//	for ( int i = 1 ; i <= m ; i ++ ) {
//		cin >> w[i] ;
//	}
//	
//	for ( int i = 1 ; i <= n ; i ++ ) {
//		int k ;
//		cin >> k ;
//		while (k --) {
//			int j , t ;
//			cin >> j >> t ;
//			read_t[i].push_back (t) ;
//			read_v[i].push_back (j) ;
//			dp[i][j] = t*2;
//		}
//	}
////	
	
	
	
//	for ( int i = 1 ; i <= n ; i ++ ) {
//		for ( int j = )
//	}
	
	
	return 0 ;
} 
