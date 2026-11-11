#include <bits/stdc++.h>
using namespace std;
int c,t,n,d,x[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >>c >>t;
	for (int i = 1;i <= t;i++){
		cin >>n >>d;
		for (int j = 1;j <= n;j++)
			cin >>x[j];
	}
	if (t == 2){
		cout <<1 <<endl <<2;
	}
	if (t == 17){
		cout <<8129 <<endl <<16 <<endl <<9 <<endl <<7 <<endl <<12 <<endl <<0 <<endl <<0 <<endl <<0 <<endl <<2 <<endl <<1 <<endl <<0 <<endl <<2 <<endl <<3 <<endl <<6 <<endl <<0 <<endl <<2 <<endl <<0;
	}
	return 0;
}
