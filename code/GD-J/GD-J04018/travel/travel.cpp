#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a!=c){
		cout<<"0000";
		return 0;
	}
	cout<<1;
	if(b[1]!=d[1]){
		cout<<"000";
		return 0;
	}
	cout<<1;
	if(b[2]+d[2]>133&&b[2]+d[2]<137){
		cout<<"00";
		return 0;
	}
	cout<<1;
	if(abs((int)b[2]-d[2])!=1){
		cout<<"0";
		return 0;
	}
	cout<<"1";
	return 0;
}
