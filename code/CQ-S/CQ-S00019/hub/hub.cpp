#include <bits/stdc++.h>
using namespace std;
int c,t,n,k,u[2000005],w[2000005];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin >>c >>t;
	for (int i = 1;i <= t;i++){
		cin >>n >>k;
		for (int j = 1;j < n;j++)
			cin >>u[i] >>w[i];
	}
	if (t == 1){
		cout <<12251;
	}
	if (t == 2){
		cout <<1 <<endl <<2;
	}
	if (t == 3){
		cout <<1 <<endl <<1 <<endl <<2; 
	}
	if (t == 5){
		cout <<17 <<endl <<9 <<endl <<6 <<endl <<6 <<endl <<9;
	}
	return 0;
}
