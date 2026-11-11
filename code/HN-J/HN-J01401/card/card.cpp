#include <bits/stdc++.h>
using namespace std;
int n,m,ans;
vector<int> a(n),b(n);
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = 0; i < n; i++){
		b[i] = a[i];
		for(int j = 0; j < i; j++){
			if(a[j] == b[i]){
				cout << i << " ";
			}
		}
	}
	return 0;
}
