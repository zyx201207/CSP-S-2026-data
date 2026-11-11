#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const ll MAXN = 5e5+5;
const ll INF = 1e18;

ll n, m, res = -INF;
ll a[MAXN], cnt = 0, tot = 0; // cnt为当前考虑中的项数, tot为耗费能量 
ll sum = 0; // sum为舍弃所选的第一位置所少耗费的能量，通过与下一位置的差来转移 

int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);cin.tie(nullptr);
	cin >> n >> m;
	for(ll i = 1; i <= n; i++){
		cin >> a[i];
	}sort(a+1, a+n+1);
	ll i = 1, j = 1; // 双指针??? 单指针 
	deque<ll> q;
	while(j <= n){
		while(!q.empty() && (a[j]-a[q.back()])*cnt+tot > m){
			cnt--;
			tot-=sum;
			ll tmp = q.front();
			q.pop_front();
			if(!q.empty())sum-=a[q.front()]-a[tmp];
			else sum = 0;
		}
		if(!q.empty()){
			tot+=(a[j]-a[q.back()])*cnt;
			sum+=a[j]-a[q.back()];
		}
		q.push_back(j);
		cnt++;
		res = max(res, cnt); 
//		cout << "截至于" << j << " 总共已有" << cnt <<"项，耗费能量为" << tot << endl; 
		j++;
	}
	cout << res << endl;
	return 0;
} 
