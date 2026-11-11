#include <bits/stdc++.h>
using namespace std;

int read(){
	int k = 0,f = 1,c = getchar();
	for(;!isdigit(c);c = getchar())
		if(c == '-')
			f = -1;
	for(;isdigit(c);c = getchar())
		k = k*10 + (c^48);
	return k*f;
}

int main(){
	int a;
	a = read();
	cout << a;
	
	return 0;
}
