#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
int a[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}
	vector<int> b[n+5];
	for(int  i = 1; i <= n; i++){
		for(int j = i; j <= n; j++){
			auto c = find(b[i].begin(),b[i].end(),a[j]);
			if(c == b[i].end()){
				b[i].push_back(a[j]);
			} else {
				b[i].erase(c,b[i].end());
				b[i].push_back(a[j]);
			}
		}
	}
	for(int i = 1; i <= m; i++){
		int ans = 0;
		for(int j = 1; j <= n; j++){
			if(find(b[j].begin(),b[j].end(),i) != b[j].end()){
				ans++;
			}
		}
		cout << ans << " ";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
