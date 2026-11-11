#include<bits/stdc++.h>
using namespace std;
string c1,c2,c3,c4;
int X,R;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>c3>>c4;
	if(c1==c3) cout<<'1';
	else{
		cout<<"0000";
		return 0;
	}
	if(c2[0]==c4[0] && c2[1]==c4[1])
		cout<<'1';
	else{
		cout<<"000";
		return 0;
	}
	if(c2[2]>='A' && c2[2]<='C') X=1;
	else X=2;
	if(c4[2]>='A' && c4[2]<='C') R=1;
	else R=2;
	if(X==R) cout<<'1';
	else{
		cout<<"00";
		return 0;
	}
	if(c2[2]-1==c4[2] || c4[2]-1==c2[2]) cout<<'1';
	else cout<<'0';
	return 0;
	fclose(stdin);
	fclose(stdout);
}
