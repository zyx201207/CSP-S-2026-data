#include<iostream>
#include<random>
using namespace std;
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c,t;
	cin >> c >> t;
	while(t--){
		srand(time(0));
		cout << rand()%6 << endl;
	}
	return 0;
}
