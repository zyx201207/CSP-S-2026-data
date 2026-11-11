#include<bits/stdc++.h>
using namespace std;
long long o,t,n,m;
pair<long long,long long> a[100010];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >> o >> t;
	while(t--){
		cin >> n >> m;
		for(int i = 0;i < n - 1; i++){
			cin >> a[i].first >> a[i].second;
		}
		cout << (n - 1) / m - 1 << endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

