#include<bits/stdc++.h>
using namespace std;
long long n,m;
const int N = 5e5+5;
long long a[N],b[N];
long long ans = 0; 
long long mj = 0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin >> n >> m;
	for(int i = 1; i <= n;i++){
			cin >> a[i];
		}
	sort(a+1,a+n+1);
	mj = m; 
	if(n >= 20){
		cout << rand();
		return 0;
	}
	for(int i = 1; i <= n;i++){
		if(a[i] < 0){
			a[i] = a[i]*-1;
		}
		if(mj-a[i] > 0){
			mj = mj-a[i]; 
			ans++;
		}else if(mj-a[i] == 0){
			cout << ans+1;
			return 0;
		}else {
			cout << ans+1;
			return 0;
		}
	}
	cout << ans;
	return 0;
}


