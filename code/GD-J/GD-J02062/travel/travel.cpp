#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	long long a,c;
	string b,d;
	cin >> a >> b >> c >> d;
	if(a != c){
		cout << "0000";
	}else{
		int k = b[0] - '0',l = d[0] - '0';
		int m = b[1] - '0',n = d[1] - '0';
		int f = 10*k + m,g = 10*l + n;
		if(f == g){
			char y = b[2],z = d[2];
			if('A' <= y && y <= 'C'){
				if('A' <= z && z <= 'C'){
					if(('A' == z && 'C' == y)||('A' == y && 'C' == z)){
						cout << "1110"; 
					}else{
						cout << "1111";
					}
				}else{
					cout << "1100";
				}
			}else{
				if('D' <= z && z <= 'F'){
					cout << "1111";
				}else{
					cout << "1100";
				}
			}
		}else{
			cout << "1000";
		}
	}
	return 0;
}
