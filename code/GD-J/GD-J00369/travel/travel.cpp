#include <bits/stdc++.h>
using namespace std;

string s1,s2,s3,s4;
int a,b,c,d;


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//02 01A 02 01B
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> s1 >> s2 >> s3 >> s4;
	a = a*10+(int)(s1[0]-'0');
	a = a*10+(int)(s1[1]-'0');
	b = b*10+(int)(s3[0]-'0');
	b = b*10+(int)(s3[1]-'0');
	//a,b   done
	if(a==b){
		cout<<"1";
	}else{
		cout << "0000";
		return 0;
	}
	c = c*10+(int)(s2[0]-'0');
	c = c*10+(int)(s2[1]-'0');
	d = d*10+(int)(s4[0]-'0');
	d = d*10+(int)(s4[1]-'0');
	if(c == d){
		cout << "1";
	}else{
		cout << "000";
		return 0;
	}if((s2[2]>='A'&&s2[2]<='C'&&s4[2]>='A'&&s4[2]<='C')||(s2[2]>='D'&&s2[2]<='E'&&s4[2]>='D'&&s4[2]<='E')){
		cout << "1";
	}else{
		cout << "00";
		return 0;
	}if(abs((int)(s2[2]-s4[2]))==1){
		cout << "1";
	}else{
		cout << "0";
		return 0;
	}
	return 0;
} 
