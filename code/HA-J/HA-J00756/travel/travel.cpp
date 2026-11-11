#include<bits/stdc++.h>
using namespace std;
long long c1,s1,c2,s2;
char sa1,sa2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>sa1>>c2>>s2>>sa2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	else{
		cout<<"1";
		if(s1!=s2){
			cout<<"000";
			return 0;
		}
		else{
			cout<<"1";
			if((sa1>='A'&&sa1<='C'&&sa2>='D'&&sa2<='E')||(sa1>='D'&&sa1<='E'&&sa2>='A'&&sa2<='C')){
				cout<<"00";
				return 0;
			}
			else{
				cout<<"1";
				if(abs(sa1-sa2)==1){
					cout<<"1";
				}
				else{
					cout<<"0";
				}
			}
		}
	}
	return 0;
}
