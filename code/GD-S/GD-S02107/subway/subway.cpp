#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int n;
	cin >> n;
	vector<long long>a(n);
	for(int i=0;i<n;++i){
		cin >> a[i];
	}
	long long ans = 0;
	for(int i=0;i<n;++i){
		if(a[i]>ans)ans=a[i];
	}
	cout << ans << endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}             
