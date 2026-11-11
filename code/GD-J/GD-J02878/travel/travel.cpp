#include <bits/stdc++.h>
using namespace std;
struct train{
	string c;
	string s;
};
train R;
train X;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> R.c >> R.s >> X.c >> X.s;
	if(R.c==X.c){
		cout << 1;
	}
	else{
		cout << "0000";
		return 0;
	}
	char r[3];
	char x[3];
	for(int i=0;i<3;i++){
		r[i]=R.s[i];
		x[i]=X.s[i];
	}if(r[0]==x[0]&&r[1]==x[1]){
		cout << 1;
	}
	else{
		cout << "000";
		return 0;
	}
	if((x[2]>='D'&&r[2]>='D')||('A'<=r[2]&&r[2]<='C'&&'A'<=x[2]&&x[2]<='C')){
		cout << 1;
	}
	else{
		cout << "00";
		return 0;
	}if((x[2]>='D'&&r[2]>='D')||(r[2]+1==x[2]||x[2]+1==r[2])){
		cout << 1;
	}
	else cout << 0;
	return 0;
} 
