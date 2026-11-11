#include<bits/stdc++.h>
//#define int long long
#define uint unsigned int
#define all(x) x.begin(),x.end()
#define inf 0x3f3f3f3f
using namespace std;
const int maxK = 5e5 + 5;
const int maxN = 5e2 + 5;
const int maxQ = 1e5 + 5;
const int maxD = 2e1 + 5;
const int di[] = {1,-1};
struct poi{
	int w,t,d = 0; //w = hall to counter
	int cr[2*maxD]; // t = counter to hall
	int pos[maxD]; //cr = index of line(s)
};int dfs(int k,int cnt);
bool check(int k);
void initvis();
int n,m,c,d,q; poi pt[maxN]; int si,ei;
int lin[maxN][maxD]; int vis[maxN]; int ans;
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i=0;i<m;i++) cin >> pt[i].w;
	for(int i=0;i<n;i++){
		int temp; cin >> temp;
		for(int j=0;j<temp;j++){
			cin >> lin[i][j] >> pt[j].t;
			pt[j].cr[d] = i; pt[j].d++;
			pt[j].pos[i] = j;
		}
	}for(int i=0;i<q;i++){
		initvis();
		cin >> si >> ei;
		cout << dfs(si,0) << endl;
	}return 0;
}bool check(int k){
	if(k == ei) return true;	
}int dfs(int k,int cnt){
	vis[k] = true; int npos; int ans = inf;
	if(check(k)) return cnt;
	for(int i=0;i<pt[k].d;i++){
		for(int j=0;j<2;j++){
			npos = lin[pt[k].cr[i]][pt[k].pos[i]+di[j]];
			if(!vis[npos]){
				cnt += pt[npos].w;
				cnt += pt[npos].t;
				vis[npos] = true;
				ans = min(ans,dfs(npos,cnt));
				cnt -= pt[npos].w;
				cnt -= pt[npos].t;
				vis[npos] = false;
			}else continue;
		}
	}cnt += ans;
}void initvis(){
	for(int i=0;i<maxN;i++)
		vis[i] = false;
	return;
}
