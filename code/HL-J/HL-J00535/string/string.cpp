#include <bits/stdc++.h>
using namespace std;
string a;
int main(){
freopen("string.in","r",stdin);
freopen("string.ans","w",stdout);
	int n = 0;
	cin >> n;
	for(int i = 0;i < n;i++){
		int b = 0;
		char g;
		cin >> b >> g;
		a += g;
	}
	int c = 0;
	for(int i = 0;i < n;i++){
		if(a[i] == a[i+1]){
			
		}else{
			c++;
		}
	}
	if(c == 0)cout << 0;
	return 0;	
}
