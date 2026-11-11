#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005],ans[300005],last[300005];

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	
	cin >> n >> m;
	int cnt = 0;
	
	for(int i = 1;i <= n;i++){
		cin >> a[i-cnt];
		last[a[i-cnt]] = i-cnt;
		if(a[i-cnt] == a[i-cnt-1]) cnt++;
	}
	
	n -= cnt;
	for(int i = 1;i <= n;i++){
		int p = i;
		while(p <= n){
			p = last[a[p]];
			ans[a[p++]]++;
		}
	}
	
	for(int i = 1;i <= m;i++){
		cout << ans[i] << " ";
	}
	return 0;
}
