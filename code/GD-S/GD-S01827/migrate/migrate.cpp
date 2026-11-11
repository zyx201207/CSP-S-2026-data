#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define fi first
#define sc second
const int N = 2e6+10,INF = 1e18;

int read(){
	int num = 0;
	char _c = getchar();
	bool neg = false;
	while(!(('0'<=_c && _c<='9') || _c=='-')) _c = getchar();
	if(_c=='-'){
		neg = true;
		_c = getchar();
	}
	while(true){
		num = num*10ll+(int)(_c-'0');
		_c = getchar();
		if(!('0'<=_c && _c<='9')) break;
	}
	if(neg) num = -num;
	return num;
}

int n,d,x[N];
int L[N],dp[N],cnt[N],precnt[N];

void solve(){
	int ans = 0;
	n=read(),d=read();
	for(int i=1;i<=n;i++) x[i]=read();
	for(int i=1,l=1;i<=n;i++){
		while(l<=i && x[i]-x[l]>d) l++;
		L[i] = l;
	}
	for(int i=1;i<=n;i++){ //i为起点 
		dp[i] = 0,cnt[i] = 1,precnt[i] = 1,precnt[i-1] = 0;
		deque<pii> dq;
		dq.push_back({dp[i],i});
		for(int j=i+1;j<=n;j++){
			if(L[j] == j) break;
			int l = max(i,L[j]);
			while(!dq.empty() && dq.front().sc<l) dq.pop_front();
			dp[j] = dq.front().fi+1;
			cnt[j] = precnt[dq.front().sc]-precnt[l-1];
			precnt[j] = precnt[j-1]+cnt[j];
			if(cnt[j]==2) ans++;
			if(cnt[l]>2) break;
			if(dq.back().fi==dp[j]) dq.pop_back();
			dq.push_back({dp[j],j});
		}
	}
	cout<<ans<<"\n";
}

int pcc[N];

void solveA(){
	int ans = 0;
	n = read(),d = read();
	for(int i=1;i<=n;i++) x[i] = read();
	for(int i=1,l=1;i<=n;i++){
		while(l<=i && x[i]-x[l]>d) l++;
		L[i] = l;
	}
	for(int i=1;i<=n;i++) dp[i] = cnt[i] = precnt[i] = pcc[i] = 0;
	
	//1为起点 
	dp[1] = 0,cnt[1] = 1,precnt[1] = 1,precnt[0] = 0;
	deque<pii> dq;
	dq.push_back({dp[1],1});
	for(int j=2;j<=n;j++){
		if(L[j] == j) break;
		int l = L[j];
		while(!dq.empty() && dq.front().sc<l) dq.pop_front();
		dp[j] = dq.front().fi+1;
		cnt[j] = precnt[dq.front().sc]-precnt[l-1];
		precnt[j] = precnt[j-1]+cnt[j];
		if(cnt[j]==2) pcc[j]++;
		if(cnt[l]>2) break;
		if(dq.back().fi==dp[j]) dq.pop_back();
		dq.push_back({dp[j],j});
	}	
	for(int i=1;i<=n;i++) pcc[i] += pcc[i-1];
	for(int i=1;i<=n;i++) ans += pcc[i];
	cout<<ans<<"\n";
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	int c,t;
	c = read(),t = read();
	if(c<=10){
		while(t--) solve();
	}
	else if(c<=12){
		while(t--) solveA();
	}
	else while(t--) solve();
	return 0;
}
