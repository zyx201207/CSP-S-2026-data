#include<bits/stdc++.h>
using namespace std;

string a,b,c,d;//小 R 的车票上的车厢号、座位号，以及小 X 的车票上的车厢号、座位号

bool check(char bbb,char ddd){
	string s = "ABCDF";
	int len = s.size();
	for(int i=1;i<len;i++){
		if((bbb==s[i-1]&&ddd==s[i])||(bbb==s[i]&&ddd==s[i-1])){
			return true;
		}
	}
	return false;
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>a>>b>>c>>d;
	if(a==c){//两张车票对应的座位是否在同一节车厢
		cout<<1;
	}
	else{
		cout<<0;
	}
	string bb = b.substr(0,2),dd = d.substr(0,2);
	if(a==c&&bb==dd){//两张车票对应的座位是否在同一节车厢的同一排
		cout<<1;
	}
	else{
		cout<<0;
	}
	char bbb = b[2],ddd = d[2];
	bool e = (bbb>='A'&&bbb<='C'&&ddd>='A'&&ddd<='C');
	bool f = (bbb>='D'&&bbb<='F'&&ddd>='D'&&ddd<='F');
	if(a==c&&bb==dd&&(e||f)){//两张车票对应的座位是否在同一节车厢的同一排，且位于过道的同一侧
		cout<<1;
	}
	else{
		cout<<0;
	}
	if(a==c&&bb==dd&&(e||f)&&check(bbb,ddd)){//两张车票对应的座位是否相邻
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
