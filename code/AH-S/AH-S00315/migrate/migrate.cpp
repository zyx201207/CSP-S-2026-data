#include <bits/stdc++.h>
#define rep(i,l,r) for(int i = (l);i <= (r);i++)
#define per(i,l,r) for(int i = (r);i >= (l);i--)
#define pb push_back
#define mk make_pair
#define fi first
#define se second
#define all(x) (x).begin(),(x).end()	
#define SZ(x) ((int)((x).size()))
#define Mod(x) ((x) % P)
#define ModE(x) ((x) %= P)
#define FastIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
using ll = long long;
using db = double;
constexpr int infI = 1 << 30;
constexpr ll infL = 1ll << 60;

const int N = 2e6 + 10;

int c,T;

int n;

ll d;

ll x[N];

#define L(id) ((id) * 2)
#define R(id) ((id) * 2 + 1)
#define LEFT L(id),l,mid
#define RIGHT R(id),mid + 1,r
#define START 1,1,n

struct Info{
	int minv;
};

struct Tag{
	int minv;
};

struct Node{
	Info info;
	Tag tag;
}seg[4 * N];

Info operator + (const Info &x,const Info &y){
	return {min(x.minv,y.minv)};
}

Tag operator + (const Tag &x,const Tag &y){
	return {min(x.minv,y.minv)};
}

Info operator + (const Info &x,const Tag &y){
	return {min(x.minv,y.minv)};
}

void update(int id){
	seg[id].info = seg[L(id)].info + seg[R(id)].info;
}

void settag(int id,Tag tag){
	seg[id].info = seg[id].info + tag;
}

void pushdown(int id){
	settag(L(id),seg[id].tag);
	settag(R(id),seg[id].tag);
	seg[id].tag = {infI};
}

void build(int id,int l,int r){
	seg[id].tag = {infI};
	if(l == r) {
		seg[id].info = {infI};
		return ;
	}
	int mid = (l + r) >> 1;
	build(LEFT);
	build(RIGHT);
	update(id);
}

void modify(int id,int l,int r,int ql,int qr,Tag tag){
	if(l == ql && r == qr){
		settag(id,tag);
		return ;
	}
	int mid = (l + r) >> 1;
	pushdown(id);
	if(qr <= mid) modify(LEFT,ql,qr,tag);
	else if(ql > mid) modify(RIGHT,ql,qr,tag);
	else modify(LEFT,ql,mid,tag),modify(RIGHT,mid + 1,qr,tag);
	update(id);
}

Info query(int id,int l,int r,int ql,int qr){
	if(l == ql && r == qr){
		return seg[id].info;
	}
	int mid = (l + r) >> 1;
	pushdown(id);
	if(qr <= mid) return query(LEFT,ql,qr);
	else if(ql > mid) return query(RIGHT,ql,qr);
	else return query(LEFT,ql,mid) + query(RIGHT,mid + 1,qr);
}
//beizeng+segmentTree

int to[26][N];

ll sum[26][N];

int maxto[N];

int maxstep[N];

int main(){
	freopen("migrate2.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&T);
	while(T--){
		scanf("%d%lld",&n,&d);
		ll ans = 0;
		rep(i,0,n + 1) maxstep[i] = 0;
		build(START);
		rep(i,1,n) scanf("%lld",&x[i]);
		for(int i = 1,j = 1;i <= n;i++){
			while(j <= n && x[j] <= x[i] + d) j++;
			to[0][i] = j - 1;
			sum[0][i] = j - 1;
		}
		maxto[n] = n;
		per(i,1,n - 1) {
			if(x[i + 1] - x[i] <= d) maxto[i] = maxto[i + 1];
			else maxto[i] = i;
		}
		// rep(i,1,n) modify(START,i,i,{maxto[i] + 1});
		rep(j,1,25) rep(i,1,n) to[j][i] = to[j - 1][to[j - 1][i]],sum[j][i] = sum[j - 1][i] + sum[j - 1][to[j - 1][i]];
		rep(i,1,n){
			int p = i;
			per(j,0,25){
				if(to[j][p] != maxto[i]) {
					p = to[j][p];
					maxstep[i] += (1 << j);
				}
			}
			if(p != maxto[i]) maxstep[i]++;
		}
		rep(i,2,n - 1){
			//1.find the postion satifying they can reach i but cannot reach i + 1
			//must no jiaodian
			//x[i] - x[j] <= d && x[i + 1] - x[j] > d
			//x[i] - d <= x[j] && x[j] <= x[i + 1] - d - 1
			//sumr-suml
			int l = lower_bound(x + 1,x + 1 + n,x[i] - d) - x;
			int r = upper_bound(x + 1,x + 1 + n,x[i + 1] - d - 1) - x - 1;
			if(l > r || i == maxto[i]) {
				continue;
			}
			ll res = 0;
			int p1 = i - 1,p2 = i;
			int step = 0;
			per(j,0,25){
				if(step + (1 << j) < maxstep[i]) {
					p1 = to[j][p1];
					res += sum[j][p1];
					step += (1 << j);
				}
			}
			res += sum[0][p1];
			step = 0;
			per(j,0,25){
				if(step + (1 << j) < maxstep[i]) {
					p2 = to[j][p2];
					res -= sum[j][p2];
				}
			}
			res -= i;
			ans += res * (r - l + 1);
			// cerr << T << " " << i << ' ' << l << ' ' << r << endl;
			// cerr << i <<  ' ' << l << ' ' << r << ' ' << p1 << ' ' << p2 << endl;
			// if(step <= maxstep[i]){
			// 	modify(START,l,r,{p1});
			// }
		}
		printf("%lld\n",ans);
	}
	return 0;
}