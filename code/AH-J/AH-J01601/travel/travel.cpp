#include <bits/stdc++.h>
using namespace std;
char a[5],b[5],c[5],d[5],c11,c22;
int x11,x22,y11,y22;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>a>>b>>c>>d;
	x11=(a[0]-'0')*10+a[1]-'0';
	y11=(b[0]-'0')*10+b[1]-'0';
	c11=b[2];c22=d[2];
	x22=(c[0]-'0')*10+c[1]-'0';
	y22=(d[0]-'0')*10+d[1]-'0';
	if(x11==x22){
		cout<<"1";
		if(y11==y22){
			cout<<"1";
			if(c11<='C'&&c22<='C'||c11>='D'&&c22>='D'){
				cout<<"1";
				if(c11<='C'&&c22<='C')
					if(abs(c11-c22)==1)	cout<<"1";
					else				cout<<"0";
				else					cout<<"1";
			}
			else	cout<<"00";
		}	
		else	cout<<"000";
	}
	else	cout<<"0000";
	return 0;
}
