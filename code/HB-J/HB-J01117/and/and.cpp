#include <bits/stdc++.h>
using namespace std;

//typedefs
typedef long long ll;
typedef pair<ll, ll> pii;

//constants
const int N = 2e5 + 7;
const ll mxi = (1ll << 32) - 1; 

//vars
int n, m;

//arrays
ll a[N];
ll zerow[N];//0 wei quan zhi
int dp[N];
priority_queue<pii> pq;

bool ans[N];
ll tot = mxi;
int cnt;

//main
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin.tie(0),ios::sync_with_stdio(0);
	cin >> n >> m;
	
	for(int i = 0; i < n; ++i){
		cin >> a[i];
	}
	sort(a, a+n);
	
	if(m == n){
		for(int i = 0;i < n; ++i){
			tot &= a[i];
		}
		cout << tot << endl;
		return 0;
	}
	if(m == 1){
		sort(a, a+n);
		cout << a[n-1] << endl;
		return 0;
	}
	/*
	ll tmp1 = mxi;
	while(tmp1){
		cout << (tmp1 & 1);
		tmp1 >>= 1;
	}
	cout << "!!!\n";*/
	
	for(int i = 0; i < n; ++i){
		zerow[i] = mxi ^ a[i];
		//cout << a[i]  << "!!!" << endl;
		/*ll tmp = zerow[i];
		
		cout << tmp << endl;
		while(tmp){
			cout << (tmp & 1);
			tmp >>= 1;
		}
		
		//cout << "!!!\n";*/
	}
	
	//cout << "m:"<< m << endl;
	for(int i = 0; i < n; ++i){
		pq.push({zerow[i],i});
		ans[i] = true;
		++cnt;
		//cout <<"i :" << i << " "<< cnt << endl;
		
		if(cnt > m){
			pii head = pq.top();
			//cout << head.first << " " << head.second << endl;
			if(zerow[i] < head.first){
				ans[head.second] = false;
				--cnt;
				pq.pop();
				//cout << "swap:" << i << ' ' << head.second << endl;
			}
			else {
				--cnt,ans[i] = false;
			}
		}
	}
	
	for(int i = 0; i < n; ++i){
		if(ans[i]){
			cout << tot <<  "!!!"<<endl ;
			tot &= a[i];
			cout << i <<' ' << a[i] << "!!!" << endl;
			ll tmp = zerow[i];
		
			cout << tmp << endl;
			while(tmp){
				cout << (tmp & 1);
				tmp >>= 1;
			}
			cout << "!!!\n" << endl;
		}
	}
	cout << tot << endl;
	
	return 0;
}
