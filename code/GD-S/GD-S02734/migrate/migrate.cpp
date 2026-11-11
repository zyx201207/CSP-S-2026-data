#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t; cin >> c >> t;
	srand(time(0));
	for(int i=1;i<=t;i++){
		cout << rand()%2455*rand()/5<< "\n";
	}
	return 0;
}
