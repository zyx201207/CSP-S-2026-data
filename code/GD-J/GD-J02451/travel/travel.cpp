#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string q, w, e, r;
	cin >> q >> w >> e >> r;
	int Q = q.size();
	int W = w.size();
	int E = e.size();
	int R = r.size();
	int a = 0, b = 0;
	for(int i = 0; i < Q; i++){
		a *= 10;
		a += q[i] - '0';
	}
	int sum = 0;
	for(int i = 0; i < E; i++){
		b *= 10;
		b += e[i] - '0';
	}
	char A, B;
	A = w[W - 1];
	B = r[R - 1];
	int c = 0, d = 0;
	c = w[0] - '0';
	c += w[1] - '0';
	d = r[0] - '0';
	d += r[1] - '0';
	if(a == b){
		cout << "1";
	}else{
		cout << "0";
	}
	if(c == d){
		cout << "1";
	}else{
		cout << "0";
	}
	if(A == 'A'){
		if(B == 'B'){
			cout << "11";
		}else if(B == 'C'){
			cout << "10";
		}else{
			cout << "00";
		}
	}else if(A == 'B'){
		if(B == 'A'){
			cout << "11";
		}else if(B == 'C'){
			cout << "11";
		}else{
			cout << "00";
		}
	}else if(A == 'C'){
		if(B == 'B'){
			cout << "11";
		}else if(B == 'A'){
			cout << "10";
		}else{
			cout << "00";
		}
	}else if(A == 'D'){
		if(B == 'F'){
			cout << "11";
		}else{
			cout << "00";
		}
	}else{
		if(B == 'D'){
			cout << "11";
		}else{
			cout << "00";
		}
	}
	return 0;
} 
