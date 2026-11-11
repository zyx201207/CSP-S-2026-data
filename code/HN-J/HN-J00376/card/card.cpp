#include<bits/stdc++.h> 
using namespace std;

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	vector<int> a(n+1),b(n+1),ans(m+1);
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	for(int k = 1;k <= n;k++){	
		int pos = 1;
		for(int i = k;i <= n;i++){
			for(int j = 1;j <= n;j++){
				if(a[i] == b[j]){
					pos = j;
				}
			}
			for(int s = pos;s <= n;s++) b[s] = 0;
			b[pos] = a[i];
			pos++;
		}
		for(int i = 1;i <= m;i++){
			ans[b[i]]++;
		}
	}
	for(int i = 1;i <= m;i++){
		if(i == a[n]) cout << n << " ";
		else cout << ans[i] << " ";
	}
	return 0;
}
