#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> b >> c >> d;
	if(a == c){
		cout << 1;
	}
	else{
		cout << "0000";
		return 0;
	}
	string ans1 = "";string ans2 = "";
	int cat1 = 0;
	while(b[cat1]>='0'&&b[cat1]<='9'){
		ans1 = ans1+b[cat1];
		cat1++;
	}
	int cat2 = 0;
	while(d[cat2]>='0'&&d[cat2]<='9'){
		ans2 = ans2+d[cat2];
		cat2++;
	}
	bool flag = false;
	int sum1 = b.length()-1,sum2 = d.length()-1;
	char x = b[sum1],y = d[sum2];
	//cout << x <<" " << y;
	//char x = b[sum1],y = d[sum2];
	if(ans1 == ans2){
		cout << 1;
		if(x == 'A'){
			if(y == 'B'||y == 'C'){
				cout << 1;
				flag = true;
			}
			else{
				cout << 0;
			}
		}
		else if(x == 'B'){
			if(y == 'A'||y == 'C'){
				cout << 1;
				flag = true;
			}
			else{
				cout << 0;
			}
		}
		else if(x == 'C'){
			if(y == 'A'||y == 'B'){
				cout << 1;
				flag = true;
			}
			else{
				cout << 0;
			}
		}
		else if((x == 'D'&&y == 'F')||(x == 'F'&&y == 'D')){
			cout << 1;
			flag = true;
		}
		else{
			cout << 0;
		}
	}
	else{
		cout << "00";
	}
	if(flag == true){
		if(y-x == 1||x-y == 1){
			cout << 1;
		}
		else{
			cout << 0;
		}
	}
	else{
		cout << 0;
	}
	return 0;
}
