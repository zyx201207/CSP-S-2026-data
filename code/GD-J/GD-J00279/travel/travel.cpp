#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d; cin >> a >>b>>c>>d;
	if(a == c){
		cout << "1";
		if((b[0] == d[0]) and (b[1] == d[1])){
			cout << "1";
			if((b[2] <= 'C' and d[2] <= 'C') or (b[2] >= 'D' and d[2] >= 'D')){
				cout << "1";
				if(abs(int(b[2] - int(d[2]))) == 1){
					cout << "1";
				}else{
					cout << "0";
				}
			}else{
				cout << "00";
			}
		}else{
			cout << "000";
		}
	}else{
		cout << "0000";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
