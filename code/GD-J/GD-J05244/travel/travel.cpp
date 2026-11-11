#include<bits/stdc++.h>
using namespace std;
int a1,a2;string s1,s2;
int chg(char c){
	return c - '0';
}
int chf(char c){
	return c - 'A' + 1;
}
int main(){
	/*
	dear editor of the stunning behaviors in CSP J/S in Guangdong
	i m the one who copyed thousands of "//freopen s 
	but i m not doing this today
	rp ++
	草泥马原来有中文
	 
	
	*/
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>s1>>a2>>s2;
	if(a1 != a2){
		cout<<"0000";
		return 0;
	}
	cout<<1;
	int nu1 = chg(s1[0]) * 10 + chg(s1[1]);
	int nu2 = chg(s2[0]) * 10 + chg(s2[1]);
	char ed1 = s1[2];
	char ed2 = s2[2];
	if (nu1 != nu2){
		cout<<"000";
		return 0;
	}
	cout<<1;
	if(!(chf(ed1) <= 3 && chf(ed2) <= 3 || chf(ed1) > 3 && chf(ed2) > 3)){
		cout<<"00";
		return 0;
	}
	cout<<1;
	if(abs(chf(ed1) - chf(ed2)) == 1){
		cout<<1;
		return 0; 
	}
	cout<<0;
}
