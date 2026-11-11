#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c) cout<<1;
	else cout<<0;
	string e=b.substr(0,2);
	string f=d.substr(0,2);
	if(e==f&&a==c) cout<<1;
	else cout<<0;
	string g=b.substr(2,1);
	string h=d.substr(2,1);
	if((g=="A"&&h=="B")||(g=="A"&&h=="C")||(g=="B"&&h=="A")||(g=="B"&&h=="C")||(g=="C"&&h=="A")||(g=="C"&&h=="B")||(g=="D"&&h=="F")||(g=="F"&&h=="D")){
		if(e==f&&a==c) cout<<1;
		else cout<<0;
	}
	else cout<<0;
	if((g=="A"&&h=="B")||(g=="B"&&h=="A")||(g=="B"&&h=="C")||(g=="C"&&h=="B")||(g=="D"&&h=="F")||(g=="F"&&h=="D")){
		if(e==f&&a==c) cout<<1;
		else cout<<0;
	}
	else cout<<0;
	return 0;
}
