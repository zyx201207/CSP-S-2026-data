#include<bits/stdc++.h>
using namespace std;
int n,m,vis[200005];
long long a[200005];
bool cmp(long long a,long long b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for (int i = 1;i <= n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1,cmp);
	int ans=a[1];
	for (int i = 1;i <= m;i++){
		ans&=a[i];
	}
	cout << ans;
	return 0;
}

