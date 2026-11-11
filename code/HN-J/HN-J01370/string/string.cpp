#include<bits/stdc++.h>
using namespace std;
char c[10000];
int a,b[10000],m =1;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >>a;
	for(int i = 1; i <= a;i++){
		cin >> b[i] >> c[i];
		if(c[i] * 1 == c[1 + i] * 1) cout << 0; 
	}
	
}
