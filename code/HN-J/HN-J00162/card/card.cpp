#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
const ll N = 5e5 + 5;
const ll M = 1e5 + 5;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;
int n,m,a[N],cnt[N],lst[N],tmp[N],dif[N],ans[N];
vector<int> g[N],E[N];
void change(int x){
	for(int i = 1;i <= m;i++){
		tmp[i] = -1;
	}
	for(int i = x;i <= n;i++){
		tmp[a[i]] = i;
	}
	int l = x;
	while(l <= n){
		if(tmp[a[l]] != l){
			cnt[a[l]]++;
			l = tmp[a[l]] + 1;
		}else{
			cnt[a[l]]++;
			l++;
		}
	}
}
void work(){
	cin >> n >> m;
	bool flag_A = 1;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
		if(a[i - 1] > a[i]){
			flag_A = 0;
		}
	}
	if(n <= 5000){
		for(int i = 1;i <= n;i++){
			change(i);
		}
		for(int i = 1;i <= m;i++){
			cout << cnt[i] << " ";
		}
		cout << "\n";
		return;
	}
	if(flag_A){
		for(int i = n;i >= 1;i--){
			dif[a[i]]++;
		}
		for(int i = 1;i <= m;i++){
			dif[i] += dif[i - 1];
			cout << dif[i] << " ";
		}
		cout << "\n";
		return;
	}
	for(int i = n;i >= 1;i--){
		if(lst[a[i]] == 0){
			lst[a[i]] = i;
			cnt[i]++;
			E[i + 1].push_back(i);
		}else{
			cnt[i]++;
			E[lst[a[i]] + 1].push_back(i);
		}
	}
	for(int i = 1;i <= n;i++){
		for(auto x : E[i]){
			cnt[i] += cnt[x];
		}
	}
	for(int i = 1;i <= n;i++){
		ans[a[i]] += cnt[i];
	}
	for(int i = 1;i <= m;i++){
		cout << ans[i] << " ";
	}
	cout << "\n"; 
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr),cout.tie(nullptr);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int oT_To = 1;
	//cin >> oT_To;
	while(oT_To--){ work();}
	return 0;
}

