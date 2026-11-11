#include <bits/stdc++.h>
#define ll long long
using namespace std;
string s1,s2,s3,s4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	if(s1 == s3){
		cout<<"1";
		ll num1 = 0,num2 = 0;
		num1 = s2[0]-'0';
		num1 *= 10;
		num1 = s2[1]-'0';
		
		num2 = s4[0]-'0';
		num2 *= 10;
		num2 = s4[1]-'0';
		if(num1 == num2){
			cout<<"1";
			char a = s2[2],b = s4[2];
			if(('A' <= a && 'A' <= b && a <= 'C' && b <= 'C') || (a >= 'D' && b >= 'D' && a <= 'F' && b <= 'F')){
				cout<<"1";
				if((a == 'A' && b == 'B') || (a == 'B' && b == 'C') || (a == 'D') && (b == 'F')){
					cout<<"1";
				} else {
					cout<<"0";
				}
			} else {
				cout<<"00";
			}
		} else {
			cout<<"000";
		}
	} else {
		cout<<"0000";
	}
	return 0;
}