#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a!=c){
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	if(b[0]!=d[0]||b[1]!=d[1]){
		cout<<"000";
		return 0;
	}
	cout<<"1";
	int tb=b[2]-'A'+1,td=d[2]-'A'+1;
	if((tb<=3&&td>3)||(tb>3&&td<=3)){
		cout<<"00";
		return 0;
	}
	cout<<"1";
	if(abs(tb-td)!=1){
		cout<<"0";
		return 0;
	}
	cout<<"1";
	return 0;
}
