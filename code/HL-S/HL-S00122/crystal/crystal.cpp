#include<bits/stdc++.h>
using namespace std;

int n,ans;
long long mxa = 0;
long long m;
const int N = 5e5 + 10,A = 1e7 + 10;
long long a[N];
int cnt[A];

void dfs(int x){
	
	if(x <= 0){
		int mx = 0;
		for(int i = 1;i <= mxa * 2;i ++){
			mx = max(mx,cnt[i]);
		}
		ans = max(mx,ans);
		return;
	}
	
	for(int i = 1;i <= n;i ++){
		cnt[a[i] + mxa]--;
		a[i]++;
		cnt[a[i] + mxa]++;
		dfs(x - 1);
		cnt[a[i] + mxa]--;
		a[i]--;
		cnt[a[i] + mxa]++;
	}
	
}

map<long long,int> a2;
vector<int> dp(1,vector<int>(1,0));

void solve2(){
	
}

int main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	cin >> n >> m;
	for(int i = 1;i <= n;i ++){
		cin >> a[i];
		a2[a[i]] ++;
		mxa = max(mxa,abs(a[i]));
	}
	for(int i = 1;i <= n;i ++){
		cnt[a[i] + mxa] ++;
	}
	if(n <= 5 && m <= 10 && mxa <= 1e3){
		dfs(m);
	}else{
		solve2();
	}
	cout << ans;
	
	return 0;
}
