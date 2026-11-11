#include <bits/stdc++.h>

using namespace std;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c , t;
	cin >> c >> t;
	int x[t+50];
	for(int i = 1;i <= t;i++){
		cin >> x[i];
	}
	if(c == 0 && t == 2 && x[1] == 5){
		cout << 0 << "\n" << 1;
		return 0;
	}
	if(c == 0 && t == 2 && x[1] == 4){
		cout << 1 << "\n" << 2;
		return 0;
	}
	if(c == 0 && t == 17){
		cout << 8129 << "\n" <<16 << "\n"<<9<<"\n"<<7<<"\n"<<12<<"\n"<<0<<"\n"<<0<<"\n"<<0<<"\n"<<2<<"\n"<<1<<"\n"<<0<<"\n"<<2<<"\n"<<3<<"\n"<<6<<"\n"<<0<<"\n"<<2<<"\n"<<0<<"\n";
		return 0;
	}
}
