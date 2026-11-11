#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	long long n, m, a[100005], ans[100005] = {0};
	cin>>n>>m;
	for(int i = 0; i < n; i++) cin>>a[i];
	for(int i = 0; i < n; i++) {
		int t[100005] = {0}, b = 0;
		for(int j = i; j < n; j++) {
			if(t[a[j]] == 0) {
				t[a[j]]++;
			}
			else {
				int f;
				for(int k = j - 1; k > i; k--) {
					if(a[k] == a[j]) f = k;
				}
				for(int k = f; k < j; k++) {
					if(t[a[k]]) b++;
					t[a[k]] = 0;
				}
				t[a[j]]++;
			}
			cout<<"i="<<i<<" j="<<j<<" ";
			for(int x = 1; x <= m; x++) {
				cout<<t[x]<<" ";
			}
			cout<<endl;
		}
		for(int j = 1; j <= m; j++) {
			ans[j] += t[j];
		}
		cout<<"ans"<<" ";
		for(int j = 1; j <= m; j++) {
			cout<<ans[j]<<" ";
		}
		cout<<endl;
	}
	for(int i = 1; i <= m; i++) {
		cout<<ans[i]<<" ";
	}
	cout<<endl;
	fclose(stdin); fclose(stdout);
	return 0;
} 
