//GZ-J00487 遵义市第四初级中学 何思佳 Trick||Treat!
#include <bits/stdc++.h>
using namespace std;
int main() {
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	int cp1,cp2;
	int sz1,sz2;
	char zf1,zf2;
	cin>>cp1>>sz1>>zf1>>cp2>>sz2>>zf2;
	int a=(int)zf1,b=(int)zf2;
	if(cp1==cp2) {
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	if(sz1==sz2) {
		cout<<"1";
	} else {
		cout<<"000";
		return 0;
	}
	if(zf1<='C'&&zf2<='C'||zf1>'C'&&zf2>'C') {
		cout<<"1";
	} else {
		cout<<"00";
		return 0;
	}
	if(a-b==1||b-a==1) {
		if(zf1=='C'&&zf2=='D') {
			cout<<"0";
			return 0;
		}
		if(zf1=='D'&&zf2=='C') {
			cout<<0;
			return 0;
		}
		cout<<"1";
	} else {
		cout<<"0";
	}
	return 0;
}

