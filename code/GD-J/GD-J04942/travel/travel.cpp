#include<bits/stdc++.h>
using namespace std;
int c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1==c2){
		cout << 1;
		if(s1/10==s2/10){
			cout << 1;
			if(((s1%10==A||B||C)&&(S2%10==A||B||C))||(S1%10==D||F&&S2%10==D||F)){
				cout << 1;
				if(s1%10 == s2%10+1||s2%10-1){
					cout << 1;
				}else
					cout << 0;
			}else
				cout << 00;
		}else
			cout << 000;
	}else
		cout << 0000;
	
	return 0;
}
