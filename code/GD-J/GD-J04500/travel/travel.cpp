#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a;
	string b;
	string c;
	string d;
	cin>>a>>b>>c>>d;
	if(a == c&&b[0] == d[0]&&b[1] == d[1]){
		cout<<1111;
	}
	else if(a == c&&b[1] != d[1]){
		cout<<1000;
	}
	else{
		cout<<"0000";
	}
	return 0;
}
