#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
#define pii pair<int,int>
#define fir first
#define sec second
const int N=2e6+5;
int n,a[N],d;
int dp[N];
deque<pii> q;
void init() {
	cin>>n>>d;
	for(int i=1; i<=n; i++) {
		cin>>a[i];
	}
	for(int i=0; i<=n; i++) {
		dp[i]=0;
	}
}
void solve() {
	int ans=0;
	for(int i=1; i<=n; i++) {
		while(!q.empty())q.pop_back();
		for(int j=i; j<=n; j++) {
			dp[j]=0;
		}
		dp[i]=0;
		q.push_front(pii{i,1});
		for(int j=i+1; j<=n; j++) {
//			cout<<"(i,j)=="<<" ("<<i<<","<<j<<")\n";
			while(!q.empty()) {
				if(a[j]-a[q.front().fir]>d) {
//					cout<<"q.pop_front() "<<q.front().fir<<" "<<q.front().sec<<endl;
					q.pop_front();
				} else break;
			}
			pii top=q.front();
			dp[j]=dp[top.fir]+1;
			if(top.sec==2)ans++;
			while(!q.empty()) {
				pii now=q.back();
				if(dp[now.fir]<=dp[j])break;
				if(dp[now.fir]>dp[j]) {
//					cout<<"q.pop_back() "<<q.back().fir<<" "<<q.back().sec<<endl;
					q.pop_back();
				}
			}
			if(dp[q.back().fir]==dp[j]) {
//				cout<<"q.back().sec+="<<top.sec<<endl;
				q.back().sec+=top.sec;

			}
//			cout<<"q.push_back() "<<j<<" "<<top.sec<<endl;
			q.push_back(pii{j,top.sec});

		}
	}
	cout<<ans<<endl;
}
void solve2() {
	int x=a[2]-a[1];
	int l=d/x;
	if(l==0) {
		cout<<0<<endl;
	}else if(l==1){
		cout<<0<<endl;
	} else {
		cout<<max(0ll,n-2*l+1)<<endl;
	}
}
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--) {
		init();
//		if(c==11||c==12)solve2();
//		else solve();
solve2();
	}
	return 0;
}