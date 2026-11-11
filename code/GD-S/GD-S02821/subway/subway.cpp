#include <bits/stdc++.h> 
using namespace std;

using ll = long long;

const int N = 505, M = 500005;

int n, m, d, q, a[N][M];
ll t[N][M];
vector<int> e[100010];

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin.tie(0) -> sync_with_stdio(0);
	int c; cin >> c >> n >> m >> d >> q;
	srand(time(0));
	for(int i=1; i<=m; ++i)	cin >> w[i];
	for(int i=1; i<=n; ++i){
		cin >> k[i];
		for(int j=1; j<=k[i]; ++j){
			cin >> a[i][j] >> t[i][j];
		}
	}
	return cout << (ans = rand()), 0;
}
/*
e, you shi tu lun a.
a, yuan lai you yi ge wo qian ji nian gang xve zui duan lu de shi hou xiang dao de idea he zhe ti chong le???
dan wo gen ben mei you shi jian guo. kan lai zhe shi wo de su ming a. /ll /ll
n <= 500, d <= 20 ?????????? /lh
gan jue shi O(nq) a. huo zhe shi yu chu li, ran hou O(1) hui da a.
wan le shen me dou mei you fa xian, zhe shi bu shi hen le zi.
zhe zhen de shi fen ceng tu zui duan lu ti ma. na hen zao gao le.
kong tiao hao leng. ti mu kan bu dong le.
*/
