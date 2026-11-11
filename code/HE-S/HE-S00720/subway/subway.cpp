// subway by A67dgt027FxdGT54 (luogu user 1417426)

#include <bits/stdc++.h>
using namespace std;
#define int long long // 10 years OI = GUNMU

// the guy on the left of me is sleeping. seems like he can not solve any problem.

// really, i think i can AC T2. -> that is impossible.

// edges cnt ~ m * lim <= 1e7

const int N = 505, M = 500005;

int C, n, m, lim, q, tExit[M], dis[N + M], isDisCorr[N + M], floyd[1005][1005];

vector<pair<int, int> > gr[N + M];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	cin >> C >> n >> m >> lim >> q;
	
	if(9 <= C && C <= 11){memset(floyd, 0x3f, sizeof(floyd));
	for(int i=1;i<=1000;i++) floyd[i][i] = 0;} 
	for(int i=1;i<=m;i++){
		cin >> tExit[i];
	}
	for(int i=1;i<=n;i++){
		int k;
		cin >> k;
		if(C <= 8){
			for(int j=1;j<=k;j++){
				int a, t;
				cin >> a >> t;
				gr[i].push_back(make_pair(n + a, t));
				gr[n + a].push_back(make_pair(i, t));
			}
		}
		else if(C <= 11){
			int a1, t1, a2, t2;
			if(k == 1) cin >> a1 >> t1;
			else{
				cin >> a1 >> t1 >> a2 >> t2;
				floyd[a1][a2] = t1 + t2;
				floyd[a2][a1] = t1 + t2;
			}
		}
	}
	
	// i want to write dij, but i am too tired. i will do sth for a rest, the write dij. -- 16:08, time left 2:30 
	
	if(9 <= C && C <= 11){
		for(int k=1;k<=m;k++)
			for(int i=1;i<=m;i++)
				for(int j=1;j<=m;j++)
					if(floyd[i][k] + floyd[k][j] < floyd[i][j]) floyd[i][j] = floyd[i][k] + floyd[k][j];
	}
	
	for(;q;q--){
		int s, e;
		cin >> s >> e;
		if(C <= 8){
			s += n, e += n;
			memset(dis, 0x3f, sizeof(dis));
			memset(isDisCorr, 0, sizeof(isDisCorr)); // duo ce bu qing kong, bao ling liang hang lei
			priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > dabidui;
			dis[s] = 0;
			dabidui.push({0, s});
			while(!dabidui.empty()){
				int u = dabidui.top().second;
				dabidui.pop();
				if(isDisCorr[u]) continue;
				isDisCorr[u] = 1;
				if(u == e) break;
				for(pair<int, int> g: gr[u]){
					int v = g.first, w = g.second;
					if(dis[u] + w < dis[v]){
						dis[v] = dis[u] + w;
						dabidui.push({dis[v], v});
					}
				}
			}
			cout << tExit[s - n] + tExit[e - n] + dis[e] << "\n";
		}
		else if(C <= 11){
			cout << tExit[s - n] + tExit[e - n] + floyd[s][e] << "\n";
		}
	}
	
	// TLE, but i can get 32 points.
	
	// i am too lazy to get 9, 10, 11, 22, 23.
	
	// i am too lazy to write migrate & hub.
	
	return 0;
}


/*

see https://github.com/A67dgt027FxdGT54 !

i found git in linux vm.

wtf. i think i accepted crystal, that is my goal this year.

---

i want to play maimai after csp-s.

yao kai shi le you

---

X X XXX
X X XXX
XX X XXX
XX X XXX
X X X XXXX
X X X XXXX
XX XX XXXXX
X X X 
X X X
X X X X 
X X X X 
X X X X X X
X X X X X X

---

HOW BORING.

---

you are right, but genshin is ...

---

zgx26n, szqyht
fqmy, 55tzbj
twydjh, gzyzjfl
sxfc, ytxsbdc

---

lzzyyqhb, jldns
cynjmdhc, lzhszxt
bcqnzjyz, qxdns
njzyfysx, bjrlcxa
xhzyzs, jsgshh
xmxlyfkxs

---

it is 16:30 now.

---

kskbl

---

nzzjts, bntsdlt
yzbykhb, zjwyldg
nzbhssz, xdtybrt
brw, bzq, blgwbzqf
nsh whp, pwltc
nyj bs, wjgwqc

zxfls, whjdn
yjyj bwlcmwl
zxfls, whjdn
nxnsdc, ntwkq

fbhlzjs, xxyyaj
nxzsqty, bxbzjkq
dsgsyhj, whzfnyz
nsdmyjh, dzwxljq

---

only feels like nothing could be better when i'm with you, when i'm with you
dancing all night pray we're next together it's a breakthrough, it's a breakthrough

---

well, i have a BIGGGG piece of bread now. enjoy it.

---

ye si na ge yang

---

<< The Story of Black & White Cats >> 

Once upon a time, there was two cats. The black one is named Shama, and the white one is named Milk.

Shama was good at singing, and Milk always watched her on TV.

"How can I look like and sing with her?" Milk thought.

"Drink the milk."

She changed as she expected.

X X X X X XXXXXXX

-

XXXX XXXX XX
XXX XXX XXXXXXX
XXXXXX XX XXXX
XXXX XXX  

---

it is 16:55 now

---

i am really lieqi.

---

yhyyypt, lhjscm
wdptlmd, qzbsyy
xfwspjs, zqwfdt
fxznyqg, azptsx

wxzsslh, yyxwfcb
edqnth, xscjdzw
abldgw, ptsxdcw
wywnfxqb, csrwld

hsbah, hbbds
shzhtzkqa
fqgqn, wjfsl
whxnzjtym

wkgwc, yzgba
qpthnghtk
wchnd, pltyl
frbdnjrwld

X X X XXX X X

---

17:00 now.
time to work.

---

XXX XXX XXXXXXX
XX  XX  XXXXXX
 

*/
