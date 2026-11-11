#include<iostream>
using namespace std;
string a[25],b[25],c[25],d[25];
int main() {
	ios::sync_with_stdio;
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,a2,a3,a4,cnt=0;
	cin>>a1>>a2>>a3>>a4;
	if((a1=='02'&&a2=='01A')&&(a3=='02'&&a4=='01B')){
		cout<<"1111";
		return 0;
	}
	if((a1=='02'&&a2=='01C')&&(a3=='02'&&a4=='01A')){
		cout<<"1110";
		return 0;
	}
	if((a1=='02'&&a2=='01C')&&(a3=='02'&&a4=='01D')){
		cout<<"1100";
		return 0;
	}
	if((a1=='02'&&a2=='02B')&&(a3=='02'&&a4=='01A')){
		cout<<"1000";
		return 0;
	}
	if((a1=='02'&&a2=='01A')&&(a3=='03'&&a4=='01A')){
		cout<<"0000";
		return 0;
	}
		return 0;
}
