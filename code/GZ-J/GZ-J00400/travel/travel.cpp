// GZ-J00400 ³ÂÒã³É 
#include<bits/stdc++.h>
using namespace std;
int n, m;
string a, b;
int s = 0;
int c = 0;
int main(){
	freopen("r", "travel.in", stdin);
	freopen("w", "travel.out", stdout);
	cin >> n >> a >> m >> b; 
	if(n == m){
		cout << 1;
	}
	else{
		cout << 0;
		cout << 0;
		cout << 0;
		cout << 0;
		return 0;
	}
	for(int i = 0; i <= a.size() - 1; i++){
		if(a[i] >= '0' && a[i] <= '9'){
			s *= 10;
			s += a[i] - '0';
		}
	}
	for(int i = 0; i < b.size(); i++){
		if(b[i] >= '0' && b[i] <= '9'){
			c *= 10;
			c += b[i] - '0';
		}
	}
	if(c == s){
		cout << 1;
	}
	else{
		cout << 0;
		cout << 0;
		cout << 0;
		return 0;
	} 
	if(a[a.size()] == 'A' && b[b.size()] == 'B' || a[a.size()] == 'B' && b[b.size()] == 'A' || a[a.size()] == 'C' && b[b.size()] == 'D' || a[a.size()] == 'D' && b[b.size()] == 'C' || a[a.size()] == 'D' && b[b.size()] == 'F' || a[a.size()] == 'F' && b[b.size()] == 'D' || a[a.size()] == 'C' && b[b.size()] == 'F' || a[a.size()] == 'F' && b[b.size()] == 'C'){
		cout << 1;
	}
	else{
		cout << 0;
		cout << 0;
		return 0;
	}
	if(a[a.size()] == 'A' && b[b.size()] == 'B' || a[a.size()] == 'B' && b[b.size()] == 'A' || a[a.size()] == 'C' && b[b.size()] == 'D' || a[a.size()] == 'D' && b[b.size()] == 'C' || a[a.size()] == 'D' && b[b.size()] == 'F' || a[a.size()] == 'F' && b[b.size()] == 'D' || a[a.size()] == 'C' && b[b.size()] == 'F'){
		cout << 1;
	}         
	else{
		cout << 0;
		return 0;
	}
	return 0;
}
