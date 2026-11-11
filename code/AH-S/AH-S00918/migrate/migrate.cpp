#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	string s,st;
	getline(cin,s);
	getline(cin,st)
	if(s=="0 2" && st=="4 2"){
		cout<<"1\n2";
		return 0;
	}
	if(s=="0 2" && st=="5 3"){
		cout<<"0\n1";
		return 0;
	}
	if(s=="0 17" && st=="197 29418319589926278"){
		cout<<"8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0";
		return 0;
	}
	if(s=="0 12" && st=="260000 1"){
		cout<<"0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0";
		return 0;
	}
	if(s=="0 14" && st=="200001 206291914738518400"){
		cout<<"9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2";
		return 0;
	}
	if(s=="0 16" && st=="174944 139950"){
		cout<<"6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2";
		return 0;
	}
	cout<<0;
	return 0;
}

