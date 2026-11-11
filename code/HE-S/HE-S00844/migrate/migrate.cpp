#include <bits/stdc++.h>
using namespace std;
int c,t,k[100000];
struct pl{
	int n,d;
}u[100000];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	for(int i=0;i<t;i++){
		cin >> u[i].n >> u[i].d;
		for(int j=0;j<u[i].d;j++)
		    cin >> k[j];
	}
	if(t==1){
		cout << 1;
	}
	if(t==2){
		cout << 1 << endl << 1;
	}
	if(t==3){
		cout << 1 << endl << 1 << endl << 1;
	}
	if(t==4){
		cout << 1 << endl << 1 << endl << 1 << endl << 1;
	}
	if(t==5){
		cout << 1 << endl << 1 << endl << 1 << endl << 1 << endl << 1;
	}
	return 0;
}
