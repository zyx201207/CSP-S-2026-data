#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a;
	cin >> a;
	int d[10000];
	int e[10000];
	int b[400008];
	for(int i = 1;i <= a;i++){
		cin >> d[i];
		char c;
		cin >> c;
		int h = c;
		e[i] = h;
	}
	int g = 0;
	for(int i = 1;i <= a;i++){
		for(int j = 1;j <= d[i];j++){
			g += 1;
			b[g] = e[i];
		}
	}
	int f = 0;
	for(int i = 1;i <= g / 2;i++){
		if(b[i] != b[g + 1 - i]){
			f += 1;
		}
	}
	cout << f;
	return 0;
}
