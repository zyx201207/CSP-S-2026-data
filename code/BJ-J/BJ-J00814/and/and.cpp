#include <bits/stdc++.h>
using namespace std;
int ans = 1,ma = -1,ans1[200010],a[200010];
int n,m;
bool use[200010];

int tentotwo(int x){
	int cnt = 0,ans = 0;
	while(x > 0){
		ans += (x % 2) * pow(10,cnt);
		x /= 2;
		cnt++;
	}
	return ans;
}

int twototen(int x){
	int cnt = 0,ans = 0;
	while(x > 0){
		ans += (x % 10) * pow(2,cnt);
		x /= 10;
		cnt++;
	}
	return ans;
}

int an(int x,int y){
	int x1 = tentotwo(x);
	int y1 = tentotwo(y);
	int ans = 0,cnt = 0;
	while(x1 > 0 && y1 > 0){
		int a = x1 % 10;
		int b = y1 % 10;
		if(a == 1 && b == 1) ans += 1 * pow(10,cnt);
		x1 /= 10;
		y1 /= 10;
		cnt++;
	}
	int ans2 = twototen(ans);
	return ans2;
}

void dfs(int deep){
	if(deep == 2) ans = ans1[deep-1];
	if(deep > 2) ans = an(ans,ans1[deep-1]);
	if(deep == m+1){
		if(ans > ma) ma = ans;
		ans = 1;
		return;
	}
	for(int i = 1;i <= n;i++){
		if(!use[i]){
			ans1[deep] = a[i];
			use[i] = true;
			dfs(deep+1);
			use[i] = false;
		}
	}
}

bool cmp(int a,int b){
	return a>b;
}

int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	dfs(1);
	cout<<ma<<endl;
	return 0;
}
