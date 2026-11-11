#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int n;
	cin >> n;
	long long ans = 0;
	vector<long long>a(n);
	for(int i=0;i<n;i++)cin >> a[i];
	
	for(int i=0;i<n;++i){
		for(int j=i+1;j<n;++j){
			if(abs(a[i]-a[j])>ans){
				ans = abs(a[i]-a[j]);
			}
		}
	}
	cout << ans << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
