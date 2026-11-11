#include <bits/stdc++.h>
using namespace std;
int n;
struct abc{
	long long ai;
	char ci;
};
vector<abc> a;
int main(){
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	cin >> n;
	int k = 0;
	for(int i = 1; i <= n; i++){
		abc x;
		cin >> x.ai >> x.ci;
		a.push_back(x);
	}
	int i = 0;
	int l = n - 1;
	long long ans = 0;
	while(i < l){
		if(a[i].ci == a[l].ci){
			if(a[i].ai > a[l].ai){
				a[i].ai -= a[l].ai;
				l--;
			}
			else if(a[i].ai == a[l].ai){
				i++;
				l--;
			}
			else{
				a[l].ai -= a[i].ai;
				i++;
			}
		}
		else{
			if(a[i].ai > a[l].ai){
				a[i].ai -= a[l].ai;
				ans += a[l].ai;
				l--;
			}
			else if(a[i].ai == a[l].ai){
				i++;
				ans += a[l].ai;
				l--;
			}
			else{
				a[l].ai -= a[i].ai;
				ans += a[i].ai;
				i++;
			}
		}
	}
	cout << ans;
	return 0;
}
