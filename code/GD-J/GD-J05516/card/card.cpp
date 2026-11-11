#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N = 5e5+5;

int a[N],t[N],cnt[N];

signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for (int i=1;i<=n;i++){
		cin >> a[i];
	}
	for (int i=1;i<=n;i++){
		for (int j=i;j<=n;j++){
			t[a[j]]++;
			if (t[a[j]] == 2){
				for (int k=i;k<=j-1;k++){
					t[a[k]]--;
				}
			}
		}
		for (int i=1;i<=m;i++){
			if (t[i] >= 1) cnt[i]++;
			t[i] = 0;
		}
	}
	for (int i=1;i<=m;i++){
		cout << cnt[i] << " ";
	}
	return 0;
}
