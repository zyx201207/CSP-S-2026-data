#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t; cin >> c >> t;
	srand(time(0));
	for(int i=1;i<=t;i++){
		cout << rand()%2145*rand()/3<< "\n";
	}
	return 0;
}
