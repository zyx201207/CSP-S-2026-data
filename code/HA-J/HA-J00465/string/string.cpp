#include <bits/stdc++.h>
using namespace std;

struct word{
	int num;
	char d[1];
}words[1001000];

bool x = false;

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a;
	cin >> a;
	for (int i = 0; i < a; i++){
		cin >> words[i].num >> words[i].d[1];
	}
	for (int i = 0; i < a - 1; i++){
		if (words[i].d[1] == words[i + 1].d[1]){
			continue;
		} else {
			x = true;
			break;
		}
	}
	
	if (x = true){
		cout << 0;
	}
	return 0;
}
