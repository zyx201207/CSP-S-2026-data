#include <bits/stdc++.h>
using namespace std;
string n[10],m[10];
string b1[20],d1[20];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int f=1;
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a!=c){
		cout<<"0000";
		f=0;
	}
	if(f){
		cout<<"1111";
	}

	return 0;
}
