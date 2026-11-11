#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		long long a[n];
		for(int i = 0;i < n;i++)cin >> a[i];
		long long sum=0;
		for(int i = 0;i < n-d-1;i++){
			if (a[i+1+d]-a[i]==1+d)sum++;
		}
		cout << sum << "\n";
	}
	return 0; 
}
