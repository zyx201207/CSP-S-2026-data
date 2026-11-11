#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;cin >> c1 >> s1 >> c2 >> s2;
	int n_1=(s1[1]-'0')+(s1[0]-'0');
	int n_2=(s2[1]-'0')+(s2[0]-'0');
	char l_1=s1[2],l_2=s2[2];
	int p_1=l_1-'A',p_2=l_2-'A';
	if(c1==c2){
		cout << 1; 
	}
	else if(c1!=c2){
		cout << "0000";
		return 0;
	}
	if(n_1==n_2){
		cout << 1;
	}
	else {
		cout << "000";
		return 0;
	}
	if(((l_1>='A'&&l_1<='C')&&(l_2>='A'&&l_2<='C'))||((l_1>='D'&&l_1<='F')&&(l_2>='D'&&l_2<='F'))){
		cout << 1;
	}
	else{
		cout << "00";
		return 0;
	}
	if(abs(p_1-p_2)==1){
		cout << 1;
	}
	else cout << 0;
	return 0;
} 
