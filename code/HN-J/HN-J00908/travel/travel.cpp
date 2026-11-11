#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin); 
	freopen("travel.out","w",stdout); 
	cin>>a>>b>>c>>d;
	if(a!=c)
		cout<<"0000";
	else{
		if((b[0]-'0')*10+(b[1]-'0')!=(d[0]-'0')*10+(d[1]-'0'))
			cout<<"1000";
		else{
			if((b[2]<='C'&&d[2]>'C')||(d[2]<='C'&&b[2]>'C'))
				cout<<"1100";
			else{
				if(abs(b[2]-d[2])==1)
					cout<<"1111";
				else
					cout<<"1110";
			}
		} 
	}
	return 0;
}
