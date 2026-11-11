#include<bits/stdc++.h>
using namespace std;
string c,c1;
string h,h1;
char ans[15];
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>h>>c1>>h1;
	
	if(c==c1) {
		cout<<'1';
	}
	else {
		cout<<"0000";
		return 0;
	}
	
	int x=(int)(h[0]-'0')*10+(int)(h[1]-'0');
	int y=(int)(h1[0]-'0')*10+(int)(h1[1]-'0');
	
	
	if(x==y) {
		cout<<'1';
	}
	else {
		cout<<"000";
		return 0;
	}
	
	if((h[2]<='C' && h1[2]<='C') || (h[2]>='D' && h1[2]>='D')) {
		cout<<'1';
	}
	else {
		cout<<"00";
		return 0;
	}
	
	int l=int(h[2]-'A');
	int l1=int(h1[2]-'A');
	
	if(abs(l1-l)==1) {
		cout<<'1';
	}
	else {
		cout<<"0";
		return 0;
	}
	return 0;
}
