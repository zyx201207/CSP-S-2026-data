#include<bits/stdc++.h>
using namespace std;

inline int qread(){
	int x = 0, f = 1;
	char c = getchar();
	for(;!isdigit(c);c=getchar()) if(c == '-') f = -1;
	for(;isdigit(c);c=getchar()) x = x*10+c-48;
	return x*f;
}

void handle_c_equal_0(){
	
}

void process(){
	int n = qread(), d = qread();
	vector<int> x(n);
	for(int i = 0; i<n; i++) x[i] = qread();
	
	// check special A
	bool _is_A = true;
	int _A_delta = x[1] - x[0];
	for(int i = 2; i<n; i++){
		if(x[i] - x[i-1] != _A_delta){
			_is_A = false;
			break;
		}
	}
	if(_is_A){
		if(_A_delta > d) printf("0\n");
		else{
			
		}	
	}
}

int main(){
	
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	int c = qread(), t = qread();
	if(c == 0) handle_c_equal_0();
	else{
		while(t--) process();
	}
	
	return 0;
}