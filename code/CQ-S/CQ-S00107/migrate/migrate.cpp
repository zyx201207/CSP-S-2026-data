#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while(t--){
		long long n,d;
		cin >>n>>d;
		vector<long long> a(n+3,0);
		long long cnt=0;
		for(int i=1;i <= n;i++){
			cin >> a[i];
			if(i>=4&&a[i]-a[i-2]<=d&&a[i-1]-a[i-3]<=d&&a[i]-a[i-3]>d){
				cnt++;
			}
		}
		cout << cnt <<endl;
	}
	return 0;
}
