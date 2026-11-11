#include<iostream>
#include<cstring>
#include<algorithm>
#define memset(dest, val, n) __builtin_memet(dest, val, n)
#define fillinf(dest) memset((dest), 0x3f, sizeof(dest));
#define fillninf(dest) memset((dest), 0xc0, sizeof(dest));
#define fillzero(dest) memset((dest), 0, sizeof(dest));
#define fropen(x) freopen(x".in", "r", stdin);freopen(x".out", "w", stdout);
#define closeios() ios::sync_with_stdio(false);cin.tie(0)
template<typename... Args>
void errorf(const char* format, Args... arg){fprintf(stderr, format, arg...);}
#define int2ll 0
#if int2ll
#define int long long
#define intEx signed
#else
#define ll long long
#define intEx int
#endif
using namespace std;

const int maxn=200005;
int n;
struct SegData{
	ll cnt;
	char c;
} x[maxn];
SegData a[maxn], b[maxn];
int la, lb;

void merge(){
	int bc=1;
	for(int i=2;i<=n;i++){
		if(x[i].c==x[i-bc].c){
			x[i-bc].cnt += x[i].cnt;
			x[i].cnt = 0;
			bc++;
		}
		else bc = 1;
	}
	bc = 0;
	for(int i=1;i<=n;i++){
		if(x[i].cnt==0)	bc++;
		else x[i-bc] = x[i];
	}
	n -= bc;
}
void split(){
	ll len=0, pre=0;
	bool oka=false;
	for(int i=1;i<=n;i++) len += x[i].cnt;
	for(int i=1;i<=n;i++){
		if(oka){
			b[++lb] = x[i];
			continue;
		}
		pre += x[i].cnt;
		if(pre<(len>>1)+(len&1)){
			a[++la] = x[i];
		}
		else{
			a[++la] = {(len>>1)-(pre-x[i].cnt), x[i].c};
			if(a[la].cnt==0) la--;
			b[++lb] = {x[i].cnt-((len>>1)-(pre-x[i].cnt))-(len&1), x[i].c};
			if(b[lb].cnt==0) lb--;
			oka = true;
		}
	}
	reverse(b+1, b+lb+1);
}
void solve(){
	ll pa=0, pb=0;
	ll ans=0;
	int i=0, j=0;
	for(;i<=la&&j<=lb;){
		while(pa<=pb&&i<=la){
			i++;
			pa += a[i].cnt;
			if(j!=0&&a[i].c!=b[j].c){
				if(pa>pb) ans += a[i].cnt-(pa-pb);
				else ans += a[i].cnt;
			}
		}
		while(pa>pb&&j<=lb){
			j++;
			pb += b[j].cnt;
			if(a[i].c!=b[j].c){
				if(pa<pb) ans += b[j].cnt-(pb-pa);
				else ans += b[j].cnt;
			}
		}
	}
	cout << ans;
}

intEx main(){
	fropen("string");
	closeios();
	cin >> n;
	for(int i=1;i<=n;i++){
		cin >> x[i].cnt >> x[i].c;
	}
	merge();
	split();
	solve();
	return 0;
}