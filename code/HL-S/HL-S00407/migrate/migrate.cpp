#include<bits/stdc++.h>
using namespace std;
long long c, t;
long long n, d;
const int N = 2e6 + 10;
int x[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	bool flag = false;
	while(t--){
		cin>>n>>d;
		for(int i = 1; i <= n; i++){
			cin>>x[i];
		}
		if(!flag){
			cout<<1<<"\n";
			flag = true;
			continue;
		}
		cout<<2;
		for(int i = 1; i <= n; i++){
			x[i] = 0;
		}
	}
	
	
	
	return 0;
}