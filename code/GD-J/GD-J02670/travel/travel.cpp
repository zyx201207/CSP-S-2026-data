#include  <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if (c1==c2) cout << 1;
	else{
		cout << 0 << 0 << 0 << 0;
		return 0;
	}
	//cout << "-----------1";
	char a=s1[0],b=s1[1],c=s2[0],d=s2[1];
	if (a==c&&b==d) cout << 1;
	else {
		cout << 0 << 0 << 0;
		return 0;
	}
	//cout << "-----------2";
	char x1=s1[2],x2=s2[2];
	if (x1>='A'&&x1<='C'&&x2>='A'&&x2<='C') cout << 1;
	else if ((x1=='D'||x1=='F')&&(x2=='D'||x2=='F')) cout << 1;
	else {
		cout << 0 << 0;
		return 0;
	}
	//cout << "-----------3";
	if (x1+1==x2||x2+1==x1) cout << 1;
	else cout << 0;
	return 0;
}
