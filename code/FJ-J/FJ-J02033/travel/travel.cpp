#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	char s11,s12,s13,s21,s22,s23;
	cin>>c1>>s11>>s12>>s13>>c2>>s21>>s22>>s23;
	if(c1==c2){
		cout<<"1";
		if(s11==s21 && s12==s22){
			cout<<"1";
			if(s13<='C' && s23<='C'){
				cout<<"1";
				if((s13<='B' && s23<='B') || (s13>='B' && s23>='B')){
					cout<<"1";
				}
				else cout<<"0";
			}
			else if(s13>='D' && s23>='D')cout<<"11";
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
