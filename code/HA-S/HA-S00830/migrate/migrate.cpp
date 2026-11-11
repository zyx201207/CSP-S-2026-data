#include<bits/stdc++.h>
using namespace std;
long long wu,t,n,d,a=1,b=2,c;
long long e[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> wu >> t;
	for(int i=1;i<=t;i++){
		cin >> n >> d;
		for(int i=1;i<=n;i++){
			cin >> e[i];
			if(d==2){
				if(n==1){
					cout << 1;
					break;
				}
				if(n==2){
					cout << 2;
					break;
				}
				for(int i=1;i<=n-3;i++){
					c=a+b;
					a=b;
					b=c;
				}
			}
			else{
				cout << 0;
			}
		}
	}
	return 0;
}
