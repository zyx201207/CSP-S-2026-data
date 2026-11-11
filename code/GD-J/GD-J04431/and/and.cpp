#include <bits/stdc++.h>
using namespace std;
long long a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	long long n,m;
	cin>>n>>m;
	for(int i = 0; i<n; i++){
		cin>>a[i];
	}
	sort(a,a+n);
	long long ans;
	int total = 0;
	if(n == m){
		ans = a[0];
		for(int i = 1; i<n; i++){
			ans = ans & a[i];
		}
	} 
	else if(m == 1){
		ans = a[n-1];
		//cout<<a[n-1]<<'\n';
	}
	else{
		for(int i = n-1; i>=0; i--){
			if(i == n-1){
				ans = a[i];
			}
			total ++;
			ans = ans & a[i];
		//	cout<<a[i]<<" "<<ans<<"\n";
			if(total == m){
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
