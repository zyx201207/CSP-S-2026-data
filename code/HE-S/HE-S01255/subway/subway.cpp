#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r" stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	if(c == 0){
		for(int i = 1;i <= n;i++){
			for(int j = i;j < n;j++){
				cout << j;
			}
		}
	}
	return 0;
} 
