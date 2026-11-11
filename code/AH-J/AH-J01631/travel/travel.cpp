#include<bits/stdc++.h>
using namespace std;
bool a1,b1,c1,d1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c&&((a[0]=='0'&&a[1]<='9')||(a[0]=='1'&&a[1]<='7'))){
		cout<<"1";
		a1=1;
	}
	else cout<<"0";
	if(b[0]==d[0]&&b[1]==d[1]&&a1==1){
		cout<<"1";
		b1=1;
	}
	else cout<<"0";
	if(((b[2]>='A'&&b[2]<='C'&&d[2]>='A'&&d[2]<='C')||(b[2]>='D'&&b[2]<='F'&&d[2]>='D'&&d[2]<='F'))&&a1==1&&b1==1){
		cout<<"1";
		c1=1;
	}
	else cout<<"0";
	if((b[2]+1==d[2]||b[2]==d[2]+1)&&a1==1&&b1==1&&c1==1)cout<<"1";
	else cout<<"0";
	return 0;
}
