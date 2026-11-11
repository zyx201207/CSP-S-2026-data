#include<bits/stdc++.h>
using namespace std;
int c1,s1,c2,s2;
char l1,l2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> l1 >> c2 >> s2 >> l2;
	if(c1!=c2){
		cout << "0000";
		return 0;
	}
	if(s1!=s2){
		cout << "1000";
		return 0;
	}
	if(l1<='C'&&l2>='D'||l2<='C'&&l1>='D'){
		cout << "1100";
		return 0;
	}
	if(l1=='F') l1='E';
	if(l2=='F') l2='E';
	if(abs(l1-l2)!=1){
		cout << "1110";
		return 0;
	}
	cout << "1111";
	return 0;
}
