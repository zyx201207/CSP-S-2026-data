#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	int a[5];
	cin >> c1>>s1>>c2>>s2;
	a[0]=(c1[0]-'0')*10+(c1[1]-'0');
	a[1]=(c2[0]-'0')*10+(c2[1]-'0');
	a[2]=(s1[0]-'0')*10+(s1[1]-'0');
	a[3]=(s2[0]-'0')*10+(s2[1]-'0');
	if(a[0]==a[1]){
		cout << 1;
	}
	else{
		cout << "0000";
		return 0;
	}
	if(a[2]==a[3]){
		cout << 1;
	}
	else{
		cout << "000";
		return 0;
	}
	if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
		if(s1[2]=='B'&&(s2[2]=='A'||s2[2]=='C')||s1[2]!='B'&&s2[2]=='B'){
			cout << 11;
		}
		else if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
			cout << 10;
		}
		else cout << "00";
	}
	if(s1[2]=='D'||s1[2]=='E'){
		if(s2[2]=='D'||s2[2]=='E'){
			cout << 11;
		}
		else{
			cout << "00";
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
