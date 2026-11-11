#include<bits/stdc++.h>
using namespace std;
int x1,x2;
string a,x,a1,a2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> x1 >> a >> x2 >> x;
	a1+=a[0];
	a1+=a[1];
	a2+=x[0];
	a2+=x[1];
	if(x1==x2){
		cout << 1;
	}
	else{
		cout << 0;
		cout << 0;
		cout << 0;
		cout << 0;
		return 0;
	}
	if(a1==a2){
		cout << 1;
	}
	else{
		cout << 0;
		cout << 0;
		cout << 0;
		return 0;
	}
	if((a[2]=='A'||a[2]=='B'||a[2]=='C')&&(x[2]=='A'||x[2]=='B'||x[2]=='C')){
		cout << 1;
	}
	else if((a[2]=='D'||a[2]=='F')&&(x[2]=='D'||x[2]=='F')){
		cout << 1;
	}
	else{
		cout << 0;
		cout << 0;
		return 0;
	}
	if((a[2]=='A'&&x[2]=='B'||a[2]=='B'&&x[2]=='A')||(a[2]=='B'&&x[2]=='C'||a[2]=='C'&&x[2]=='B')||(a[2]=='D'&&x[2]=='F'||a[2]=='D'&&x[2]=='F')) {
		cout << 1;
	}
	else{
		cout << 0;
	}
	return 0;
}
