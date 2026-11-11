#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2000002;
int c,t,n,d;
int a[N];
signed main(){
	freopen("migrate4.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	
	cin>>c>>t;
	while(t--){
		int ans = 0;
		cin>>n>>d;
		for(int i = 1; i <= n; i++){
			cin>>a[i];
		}
		
		int cd = a[2] - a[1];
		int nnn = d / cd;
		if(nnn > 1){
			ans = (n - nnn - 1)*(n - nnn) / 2;
		}else{
			ans = 0;
		}
		cout<<ans<<endl;
	}
	return 0;
}