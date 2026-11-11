#include<bits/stdc++.h>
using namespace std;
#define int long long
#define debug(n) cout << #n << " = " << n << "\n";
#define deb(n) cout << #n << " = " << n << "    ";
#define div() cout << "\n---------------------\n";
int a,b;string c,d;
bool flag;
void check1(){
	if(a == b){cout << "1";}
	else{
		cout << "0";
		flag = 1;
	}
}
void check2(){
	if(flag){
		cout << "0";return;
	}
	if(c[0] == d[0] && c[1] == d[1]){
		cout << "1";
	}
	else{
		cout << "0";flag = 1;
	}
}
void check3(){
	if(flag){
		cout << "0";return;
	}
	if(c[2] == 'A' || c[2] == 'B' || c[2] == 'C'){
		if(d[2] == 'A' || d[2] == 'B' || d[2] == 'C'){
			cout << "1";
		}
		else{
			cout << "0";flag = 1;
		}
	}
	else if(c[2] == 'D' || c[2] == 'F'){
		if(d[2] == 'D' || d[2] == 'F'){
			cout << "1";
		}
		else{
			cout << "0";flag = 1;
		}
	}
}
void check4(){
	if(flag){
		cout << "0";return;
	}
	if(c[2] == 'A'){
		if(d[2] == 'B'){
			cout << "1";
		}
		else{
			cout << "0";
		}
	}
	else if(c[2] == 'B'){
		if(d[2] == 'A' || d[2] == 'C'){
			cout << "1";
		}
		else{
			cout << "0";
		}
	}
	else if(c[2] == 'C'){
		if(d[2] == 'B'){
			cout << "1";
		}
		else{
			cout << "0";
		}
	}
	else if(c[2] == 'D'){
		if(d[2] == 'F'){
			cout << "1";
		}
		else{
			cout << "0";
		}
	}
	else if(c[2] == 'F'){
		if(d[2] == 'D'){
			cout << "1";
		}
		else{
			cout << "0";
		}
	}
}
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> c >> b >> d;
	check1();
	check2();
	check3();
	check4();
	return 0;
}
