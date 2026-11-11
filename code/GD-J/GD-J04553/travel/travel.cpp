#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,c,n = 1;
	char b[MAXN],d[MAXN];
	cin >> a;
	for(int i = 1;i <= 3;i++){
		cin >> b[i];
	}
	cin >> c;
	for(int i = 1;i <= 3;i++){
		cin >> d[i];
	}
	if(a == c)cout << 1;
	else {
		cout << 0;
		n = 0;
	}
	if(n == 1 && b[1] == d[1] && b[2] == b[2])cout << 1;
	else {
		cout << 0;
		n = 0;
	}
	if(n == 1 && ((b[3] == 'A' || b[3] == 'B' || b[3] == 'C') && (d[3] == 'A' || d[3] == 'B' || d[3] == 'C')) || ((b[3] == 'F' || b[3] == 'D') && (d[3] == 'F' || d[3] == 'D')))cout << 1;
	else {
		cout << 0;
		n = 0;
	}
	if(n == 1 && (b[3] - 1 == d[3] || b[3] + 1 == d[3]))cout << 1;
	else cout << 0;
	return 0;
} 
