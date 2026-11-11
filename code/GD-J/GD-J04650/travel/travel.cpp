#include<bits/stdc++.h>
using namespace std;
string c1,c2,w1,w2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>w1>>c2>>w2;
	if(c1==c2)cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(w1[0]==w2[0]&&w1[1]==w2[1])cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if((w1[2]<='C'&&w2[2]<='C')||(w1[2]>'C'&&w2[2]>'C'))cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	if((w1[2]<='C'&&abs(w1[2]-w2[2])==1)||w1[2]>'C')cout<<1;
	else cout<<0;
	return 0;
} 
