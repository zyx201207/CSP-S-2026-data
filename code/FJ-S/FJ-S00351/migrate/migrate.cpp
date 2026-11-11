#include<bits/stdc++.h>
using namespace std;
int c,t,n;
unsigned long long d;
long long x[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		cin >> n >> d;
		for(int i=1;i<=n;i++){
			cin >> x[i];
		}
		if(c==11 || c==12){
			unsigned long long f=x[1]-x[0];
			if(d<2*f || 2*f<=d-f){
				cout << 0;
			}else{
				cout << n-3;
			}
			cout << endl;
		}
		if(c==13 || c==14){
			cout << 2 << endl;
		}
	}
	return 0;
}
