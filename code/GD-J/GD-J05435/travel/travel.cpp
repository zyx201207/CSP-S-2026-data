#include <bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
struct vis{
	int c,s;
	char k;
};
vis a[3],b[3];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	a[1].k=s1[2];
	b[1].k=s2[2];
	if(c1[0]-'0'==0) a[1].c=c1[1]-'0';
	else a[1].c=(c1[0]-'0')*10+c1[1]-'0';
	if(c2[0]-'0'==0) b[1].c=c2[1]-'0';
	else b[1].c=(c2[0]-'0')*10+c2[1]-'0';
	
	if(s1[0]-'0'==0) a[1].s=s1[1]-'0';
	else a[1].s=(s1[0]-'0')*10+s1[1]-'0';
	if(s2[0]-'0'==0) b[1].s=s2[1]-'0';
	else b[1].s=(s2[0]-'0')*10+s2[1]-'0';
	
	if(a[1].c == b[1].c) cout << "1";
	else{
		cout << "0000";
		return 0;
	} 
	if(a[1].s == b[1].s){
		cout << "1";
		if(a[1].k>='A'&&a[1].k<='C'&&b[1].k>='A'&&b[1].k<='C'){
			cout << "1";
			if(a[1].k-b[1].k==1||a[1].k-b[1].k==-1) cout << "1";
			else cout << "0";
		}
		else if(a[1].k>='D'&&a[1].k<='F'&&b[1].k>='D'&&b[1].k<='F'){
			cout << "1";
			if(a[1].k-b[1].k==1||a[1].k-b[1].k==-1) cout << "1";
			else cout << "0";
		}
		else cout << "00";
	}
	else cout << "000";
	
} 
