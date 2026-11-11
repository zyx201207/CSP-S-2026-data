#include <bits/stdc++.h>
#define int long long
using namespace std;
bool Mbe;
const int N =1e6+334;
int n,m;
int ans=-1;
int a[N];
unordered_map<int,int> mp;
unordered_map<int,int> vis;
struct node{
	int num, cnt, d;
	bool friend operator < (node a, node b){
		if (a.cnt == b.cnt) return a.d> b.d;
		return a.cnt < b.cnt;
	}
};
priority_queue<node> q;

bool Med;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
//	freopen("D:\\down\\crystal\\crystal4.in","r",stdin);
//	freopen("crystal.out","w",stdout); 
//	cerr<<"Mem: " << (&Mbe-&Med) / 1048576.0 << "MB\n";
	clock_t st,ed;
	st=clock();
	cin >> n >> m;
	for (int i =1; i <= n;i++){
		cin >> a[i];
		mp[a[i]]++;
	}
	sort(a+1,a+1+n,[&](int x, int y){
		return x > y;
	});
	int mid = 0;
	if ((n % 2) == 1) mid = a[(n+1)/2];
	else mid = (a[n/2] + a[(n/2) + 1] ) / 2;
	for (int i =1; i <= n;i++){
		if (!vis[a[i]]){
			
			q.push({a[i], mp[a[i]], llabs(a[i]-mid)});
			vis[a[i]]=1;
		}
		if (ans - mp[a[i]] < 0 ) ans = mp[a[i]];
	}
	if (ans==n){
		cout << ans << '\n';
		return 0;
	}

	while (!q.empty()){
		int tmp=m,res=0;
		auto cur = q.top();	q.pop();
		res = cur.cnt;
		for (int i = 1; i <= n;i++){
			if (a[i] >= cur.num) continue;
			int nd = (cur.num - a[i]);
			if (tmp >= nd ){
				tmp-=nd;
				res+=1;
			}
			else break;
			if (res == n){
				cout << res << '\n';
				return 0;
			}
		}
			
	
		if (ans < res) ans= res;
		if ((double)(clock() * 1.0 / CLOCKS_PER_SEC)  >= 0.97){
			if (ans < res) ans= res;
			cout << ans << '\n';
			return 0;
		}
	}
	
	
	cout << ans << '\n';
//	cerr<< "Time: " << (double)(clock() * 1.0 / CLOCKS_PER_SEC) << '\n'; 
	return 0; 
} 
