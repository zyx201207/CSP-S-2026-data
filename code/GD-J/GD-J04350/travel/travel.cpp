#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
string a, b, c, d;
const char s[10] = "ABC DF";
int main(){
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	
	cin >> a >> b >> c >> d;
	int ok = 0;
	if(a == c) printf("1"), ok = 1;
	else printf("0");
	
	int ok1 = 0;
	if(ok == 1){
		int n = b.size(), B = 0;
		for(int i = 0; i < n - 1; i++)
			B = B * 10 + (b[i] - '0');
		
		n = d.size();
		int D = 0;
		for(int i = 0; i < n - 1; i++)
			D = D * 10 + (d[i] - '0');
		if(B == D) printf("1"), ok1 = 1;
		else printf("0");						
	}else{
		printf("0");
	}
	
	if(ok == 1 && ok1 == 1){
		int n = b.size();
		int x = b[n - 1], y = d[n - 1];
		if(x >= 'A' && x <= 'C' && y >= 'A' && y <= 'C') printf("1");
		else if(x >= 'D' && x <= 'F' && y >= 'D' && y <= 'F') printf("1");
		else printf("0");
	}else{
		printf("0");
	}
	
	if(ok == 1 && ok1 == 1){
		int n = b.size();
		int x = (b[n - 1] - 'A'), y = (d[n - 1] - 'A');
		if((s[x + 1] == s[y] && x + 1 < n) || (s[x - 1] == s[y] && x - 1 > 0)) printf("1");
		else printf("0");		
	}else{
		printf("0");
	}
}
