#include <bits/stdc++.h>
using namespace std;
int m,n;
int s[100];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> m >> n;
	for(int i=1;i<=m;i++){
		cin >> s[i];
	}
	if(n == 1){
		cout << m;
	}else if(n == 2){
		cout << m/2 << m/2-1;
	}
	return 0;
} 
