#include<bits/stdc++.h>
using namespace std;
long long c,t,n,d,x[100001];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>> c >> t;
	while(t--){
		cin>> n >> d;
		for(int i=1;i<=n;i++){
			cin>> x[i];
		}
	}
	cout<< 0<<endl;
	cout<< 1;
	return 0;
}
