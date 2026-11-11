
#include<iostream>
using namespace std;
const int N=2e6+5;
int c,t,n,d,x[N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> c >> t;
//	if(c==11||c==12){
		while(t--){
			cin >> n >> d;
			for(int i=1;i<=n;i++){
				cin >> x[i];
			}
			if(2*(x[2]-x[1])>d&&n>=4){
				cout << "0" << endl;
			}
			else{
				cout << n-3 << endl;
			}
		}
//	}
	return 0;
}

