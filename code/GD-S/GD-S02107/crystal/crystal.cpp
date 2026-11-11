#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	cin >> n;
	vector<long long>a(n);
	for(int i=0;i<n;++i){
		cin >> a[i];
	}
	long long ans = 0;
	for(int i=0;i<n;++i){
		if(a[i]%2==0)ans++;
	}
	cout << ans << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}                       
