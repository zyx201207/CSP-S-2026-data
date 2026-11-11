//GZ-J00201 Ξ€ά²ηλ 
#include<bits/stdc++.h>
using namespace std;
string a,ac,b,bc;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>ac>>b>>bc;
	if(a==b){
		cout<<1;
		if(ac[0]==bc[0]&&ac[1]==bc[1]){
			cout<<'1';
			if(ac[2]>='A'&&ac[2]<='C'&&bc[2]>='A'&&bc[2]<='C'){
				cout<<'1';
				if(abs(ac[2]-bc[2])==1)	cout<<'1';
				else	cout<<'0';
			}
			else	cout<<"00";
		}
		else	cout<<"000";
	}
	else	cout<<"0000";
	return 0; 
}
