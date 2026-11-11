#include<bits/stdc++.h>
using namespace std;
string c1,c2,c3,c4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>c3>>c4;
	if(c1 == c3){
		cout<<1;
		if(c2[0] == c4[0] && c2[1] == c4[1]){
			cout<<1;
			char c11 = c2[2],c22 = c4[2];
			if(c11>='A'&&c11<='C'&&c22>='A'&&c22<='C'){
				cout<<1;
				if((c11 == 'A' && c22 == 'B' || c11 == 'B' && c22 == 'C' || c11 == 'D' && c22 == 'F') || (c11 == 'B' && c22 == 'A' || c11 == 'C' && c22 == 'B' || c11 == 'F' && c22 == 'D')) cout<<1;
				else cout<<0;
			}
			else if(!(c11>='A'&&c11<='C'&&c22>='A'&&c22<='C')) cout<<0<<0;
			
		}
		else if(!(c2[0] == c4[0] && c2[1] == c4[1]))cout<<0<<0<<0;
	}
	else if(c1 != c3)cout<<0<<0<<0<<0;
	return 0;
}
