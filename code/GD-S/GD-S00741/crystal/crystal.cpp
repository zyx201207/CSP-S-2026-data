#include<bits/stdc++.h>
using std::cin;
using std::cout;
using std::endl;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define ROF(i,a,b) for(int i=(a);i>=b;--i)
#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))
#define int long long
typedef std::pair<int,int> pii;
const int INF = 0x3f3f3f3f;
const int MAXN = (int)5e5+10;

int read(){
	int x=0,f=1;char c = getchar();
	for(;!isdigit(c);c=getchar()) if(c == '-') f = -1;
	for(;isdigit(c);c=getchar()) x = (x<<3)+(x<<1)+(c^48);
	return x*f;
} 
template<typename T>
void write(T x){
	if(x<0){putchar('-');x=-x;}
	if(x>9) write(x/10);
	putchar(x%10+'0');
}
void IO(){
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
}

int n,m,sum,l,ans,t,a[MAXN];
std::map<int,int>cnt;

/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
signed main(){
	IO();
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin>>n>>m;
	FOR(i,0,n) cin>>a[i],++cnt[a[i]]; 
	std::sort(a,a+n);
	int len = std::unique(a,a+n) - a;
	
	t = ans = cnt[a[0]];
	l = 0;
	
	FOR(r,1,len){
		sum += (a[r]-a[r-1])*t;
		t += cnt[a[r]];
		while(sum > m){
			if((a[r]-a[l])*cnt[a[l]]>sum-m){
				int reduce = ceil((sum-m)*1.0/(a[r]-a[l]));
				cnt[a[l]] -= reduce;
				t -= reduce;
				sum -= (a[r]-a[l])*reduce;
			}else{
				t -= cnt[a[l]];
				sum -= (a[r]-a[l])*cnt[a[l]];
				cnt[a[l]] = 0;
				++l;
			}
		}
		ans = max(ans,t);
	}
	
	cout<<ans;
	return 0;
}

