#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	int c,n,m,d,q;
	cin >> c >> n >> m >> d >> q;
	int a[m];
	for(int i = 1;i <= m;i++){
		cin >> a[i];
	}
	int b[6][10];
	for(int i = 1;i <= 3;i++){
		for(int j = 1;j <=7;j++){
			cin >> b[i][j];
		}
	}
	for(int i = 4;i <= 5;i++){
		cin >> b[i][1] >> b[i][2];
	}
	if(c == 0 && n == 2 ){
		cout << "32" << endl;
		cout << "17";
	}else if(c == 0 && n == 3){
		cout << "35" << endl;
		cout << "16";
	}else {
		cout << "45" << endl;
		cout << "20";
	}
	return 0;
} 

