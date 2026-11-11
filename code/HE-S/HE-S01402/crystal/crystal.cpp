#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[n+5];
	int sum = 0;
	for(int i= 1; i <= n; i++) {
		cin>>a[i];
		sum += a[i];
	}
	sum /= n;
//	sort(a+1,a+n+1);
	int ans = 0;
	bool ok = false;
	for(int i = 1;i <= n;i++){
		if(a[i] == a[i+1]){
			ok = true;
		}
	}
	if(ok){
		cout<<n<<endl;
		return 0;
	}
	for(int i = 1; i <= n; i++) {
		if(a[i] <= sum || a[i] <= sum + 1) {
  			ans = i;
		}
	}
	int temp = 0;
	if(ans > n){
		sum = a[n];
		ans = a[n];
	}else{
		sum = a[ans];
	}
	for(int i = ans;i >= 1;i--){
		m -= sum - a[i];
		temp ++;
		if(m == 0){
			cout<<temp<<endl;
			return 0;
		}else if(m < 0){
			cout<<temp - 1<<endl;
			return 0;
		}	
	}
	return 0; 
}
