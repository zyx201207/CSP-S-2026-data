#include<bits/stdc++.h>
#define ll long long
using namespace std;
char c11,c12,c21,c22,s11,s12,s13,s21,s22,s23,d1=-1,d2=-1;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c11>>c12;
	cin>>s11>>s12>>s13;
	cin>>c21>>c22;
	cin>>s21>>s22>>s23;
	if(c11!=c21||c12!=c22) {
		cout<<"0000";
		return 0;
	} else {
		cout<<1;
		if(s11!=s21||s12!=s22) {
			cout<<"000";
			return 0;
		} else {
			cout<<1;
			if(s13=='A'||s13=='B'||s13=='C'){
				d1=1;
			}
			if(s23=='A'||s23=='B'||s23=='C'){
				d2=1;
			}
			if(d1!=d2){
				cout<<"00";
				return 0;
			}
			else{
				cout<<1;
				if(abs((int)s23-(int)s13)!=1){
					cout<<"0";
					return 0;
				}
				else cout<<1;
			}
		}
	}
	return 0;
}
