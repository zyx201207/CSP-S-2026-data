#include <bits/stdc++.h>
using namespace std;
struct rlts{
	int id;
	int pid = 0;
	string wr;
} a, b;
int f = 0;
int main(){
	//ÌâÄ¿£ºtravel
	ios :: sync_with_stdio(false);
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	cin >> a.id >> a.wr >> b.id >> b.wr;
	if(a.id == b.id){
		cout << 1;
		f = 1;
	}
	else{
		cout << 0;
	}
	a.pid += a.wr[0] - '0';
	a.pid *= 10;
	a.pid += a.wr[1] - '0';
	b.pid += b.wr[0] - '0';
	b.pid *= 10;
	b.pid += b.wr[1] - '0';
	if(f == 1){
		if(a.pid == b.pid){
			cout << 1;
			f = 2;
		}
		else{
			cout << 0;
		}
	}
	else{
		cout << 0;
	}
	if(f == 2){
		if(a.wr[2] == 'A'){
			if(b.wr[2] == 'B'){
				cout << 11;
			}
			else if(b.wr[2] == 'C'){
				cout << 10;
			}
			else{
				cout << "00";
			}
		}
		else if(a.wr[2] == 'B'){
			if(b.wr[2] == 'A' || b.wr[2] == 'C'){
				cout << 11;
			}
			else{
				cout << "00";
			}
		}
		else if(a.wr[2] == 'C'){
			if(b.wr[2] == 'B'){
				cout << 11;
			}
			else if(b.wr[2] == 'A'){
				cout << 10;
			}
			else{
				cout << "00";
			}
		}
		else if(a.wr[2] == 'D'){
			if(b.wr[2] == 'F'){
				cout << 11;
			}
			else{
				cout << "00";
			}
		}
		else if(a.wr[2] == 'F'){
			if(b.wr[2] == 'D'){
				cout << 11;
			}
			else{
				cout << "00";
			}
		}
		else{
			cout << "00";
		}
	}
	else{
		cout << "00";
	}
	return 0;
}
