#include<bits/stdc++.h>
//#define int long long
using namespace std;
int n,m,a[200002],ans[200002];
void ff(int i){
	int b[200002];
	for(int j = i;j <= n;j++){
		b[j]=a[j];
	}
	for(int j = i;j <= n;j++){
		int t=n;
		if(b[j] == 0)continue;
		while(b[t] != b[j] &&t>j){
			t--;
//			cout << t;
		}
		for(int k = j+1;k <= t;k++){
			if(b[k] == 0)continue;
			b[k]=0;
		}
	}
	for(int j = i;j <= n;j++){
		if(b[j] == 0)continue;
		ans[b[j]]++;
//		cout << b[j] << " ";
	}
//	cout << endl;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	
	cin >> n >> m;
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++){
//		cout << "Yes" << endl;
		ff(i);
	}
	for(int i = 1;i <= m;i++){
		cout << ans[i] << " ";
	}
	return 0;
}
/*
4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1
*/
