#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int cx,zw,xcx,xzw;
	char r,x;
	scanf("%d %d%c %d %d%c",&cx,&zw,&r,&xcx,&xzw,&x);
	if(cx==xcx){
		cout << 1;
	}else{
		cout << "0000" << endl;
		return 0;
	}
	if(zw==xzw){
		cout << 1;
	}else{
		cout << "000" << endl;
		return 0;
	}
	if((r>='A' && r<='C' && x>='A' && x<='C') || (r>='D' && r<='F' && r!='E' && x>='D' && x<='F' && x!='E')){
		cout << 1;
	}else{
		cout << "00" << endl;
		return 0;
	}
	if((r=='A'&&x=='B') || (r=='B' && x=='C') || (r=='D' && x=='F')){
		cout << 1;
	}else{
		cout << 0;
	}
	return 0;
}
