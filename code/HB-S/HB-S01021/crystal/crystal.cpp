#include <bits/stdc++.h>
using namespace std;

//typedefs
typedef long long ll;

//constants
const int N = 5e5 + 7;

//vars
ll n, m;

ll a[N];
ll pre[N];

//functions 
bool check(ll st, ll x){//sheng ji ji ke shui jing
	ll sl = a[x];
	ll sum = pre[x] - pre[st - 1];
	//cout << "check " << x << " :";
	//cout << sl <<" "<<sum<<endl;
	if(((x - st) + 1) * sl - sum <= m)return true;
	else return false;
}

//main
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0),cout.tie(0);
	ios::sync_with_stdio(false);
	scanf("%lld%lld", &n, &m);
	
	for(int i = 1; i <= n; ++i){
		scanf("%lld", &a[i]);
		//cout << i << endl;
	}
	
	sort(a + 1, a + n + 1);
	
	for(int i = 0; i < n; ++i){
		pre[i] = pre[i - 1] + a[i];
		
	}
	
	
	/*
	for(int i = 1; i <= n; ++i){
		cout << pre[i]<<endl;
		
	}*/
	/*
	for(int i = 1; i <= n; ++i){
		for(int j = i;j <= n; ++j){
			cout << check(i, j) << endl;
		}
	}*/
	
	ll ans = INT_MIN;
	for(int i = 1; i <= n; ++i){
		ll l = i, r = n;
		while(l < r){
			//cout << l << ' ' << r << endl;
			int mid = ((l + r) >> 1) + 1;
			if(check(i, mid)){
				l = mid;
			}else{
				r = mid - 1;
			}
		}
		ans = max(ans, l - i + 1);
	}
	
	printf("%lld", ans);
	return 0;
}
