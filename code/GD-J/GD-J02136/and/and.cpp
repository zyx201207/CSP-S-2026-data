#include<bits/stdc++.h>
using namespace std;

int num[200005];
int cnt[200005];

int n, m, ans;

int change(int x){
	int cnt=0;
	while(x!=0){
		if(x%2==1) cnt++;
		x/=2;
	}
	return cnt;
}

bool cmp(int x, int y){
	if(change(x)!=change(y)) return change(x)>change(y);
	else return x>y;
}

int main(){
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i=1; i<=n; i++){
		cin >> num[i];
	}
	sort(num+1, num+n+1, cmp);
	ans=num[1];
	for(int i=2; i<=m; i++){
		ans=num[i]&ans;
	}
	cout << ans;
}
