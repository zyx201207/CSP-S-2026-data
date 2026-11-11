#include <bits/stdc++.h>
using namespace std;
int c,t;
long long x[2000010];
long long n,d;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(long long i = 1;i <= n;i++){
			cin>>x[i];
		}
		bool b;
		for(long long i = 2;i < n;i++){
			b = true;
			if(x[i - 1] - x[i] == x[i] - x[i + 1]){
				b = true;
			}
			else{
				b = false;
				break;
			}
		}
//		if(b == true){
//			cout<<"true"<<'\n';
//		}
//		else{
//			cout<<"false"<<'\n'; 
//		}
		if(b){
//			cout<<222<<'\n';
			if(d <= abs(x[1] - x[2])){
				cout<<0;
			}
//			else if(x[1] < 0){
//				cout<<0;
//			}
			else{
				cout<<((n % d) / 6) + 2;
			}
			cout<<'\n';
		}
	}
	return 0;
}
