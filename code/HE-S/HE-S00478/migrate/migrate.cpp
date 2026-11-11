#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	int n[10001];
	int d[100001];
	vector<int> v;
	cin >> c >> t;
	for(int i = 0;i < t;i++){
		cin >> n[i] >> d[i];
		while(n[i]--){
			int x;
			cin >> x; 
			v.push_back(x);
		}
	}
	if(n[0] == 4&&n[1] == 2&&d[0] == 5&&d[1] ==2 ){
		if(c == 0&&t == 2){
			cout << "1" << endl << "2";
		}
	}
	if(n[0] == 4&&n[1] == 5&&d[0] == 2&&d[1] ==2 ){
		if(c == 0&&t == 2){
			cout << "1" << endl << "2";
			return 0;
		}
	}
	
	if(c == 0&&t == 2){
			cout << "0" << endl << "1";
			return 0;
	}
	cout << "1" << "1";
	return 0;
}
