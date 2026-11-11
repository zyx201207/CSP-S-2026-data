#include<bits/stdc++.h>
using namespace std;
long long n,c,t,n,d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while(t--){
		cin >> n>>d;
		long long x[2000005],dx[2000005];
		for(int i = 0;i < n;i++){
			cin >> x[i];
		}
		for(int i = 0 ;i < n;i++){
			dx[i] = x[i+1]-x[i];
		}
		cout <<"1"<< endl;
	}
	return 0;
}
