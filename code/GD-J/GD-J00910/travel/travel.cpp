#include<bits/stdc++.h>
using namespace std;
string a,b,la,lb;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> la >> b >> lb;
	if(a!=b){
		cout << "0000" << '\n';
		return 0;
	}
	if(la[0]+la[1]!=lb[0]+lb[1]){
		cout << "1000" << '\n';
		return 0;
	}
	if(((la[2]=='A'||la[2]=='B'||la[2]=='C')&&(lb[2]=='D'||lb[2]=='F'))||((lb[2]=='A'||lb[2]=='B'||lb[2]=='C')&&(la[2]=='D'||la[2]=='F'))){
		cout << "1100" << '\n';
		return 0;
	}
	if((la[2]=='A'&&lb[2]=='C')||(lb[2]=='A'&&la[2]=='C')){
		cout << "1110" << '\n';
		return 0;
	}
	cout << "1111" << '\n';
	return 0;
}
