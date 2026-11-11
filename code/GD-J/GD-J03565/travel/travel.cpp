#include<bits/stdc++.h>
using namespace std;
char cy[6],sy[6];
int cx,sx;
bool check(char a[],char b[]){
	int ta=(int)a[2];
	int tb=(int)b[2];
	if(abs(ta-tb)==1) return true;
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>cx>>cy>>sx>>sy;
	if(cx==sx){
		cout<<'1';
	}else{
		cout<<'0';
	}
	char t,k;
	string a,b;
	if(cy[0]==sy[0]&&cy[1]==sy[1]){
		cout<<'1';
		if(cy[1]<='C'&&sy[1]<='C'){
			cout<<'1';
		}else if(cy[2]>='D'&&sy[2]>='D'){
			cout<<'1';
		}else{
			cout<<'0';
		}
	}
	if(check(cy,sy)){
		cout<<'1';
	}else{
		cout<<'0';
	}
	return 0;
}
