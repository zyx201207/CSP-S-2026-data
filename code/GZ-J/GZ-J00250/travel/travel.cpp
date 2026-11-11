//GZ-J00250 贵阳市新世界学校 李宗运 
#include<bits/stdc++.h>
using namespace std;
char b[15],d[15];
int a,c,aa,cc;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	aa=(int(b[0])-48)*10+int(b[1])-48;
	cc=(int(d[0])-48)*10+int(d[1])-48;
	if(a==c)cout<<'1';
	else{
		cout<<"0000";
		return 0;
	}
	if(aa==cc)cout<<'1';
	else {
		cout<<"000";
		return 0;
	}
	if(b[2]<='F'&&b[2]>='D'&&d[2]<='F'&&d[2]>='D')
		cout<<"11";
	else {
		if(b[2]<='C'&&b[2]>='A'&&d[2]<='C'&&d[2]>='A')cout<<'1';
		else{
			cout<<"00";
			return 0;
		} 
		if(int(b[2])==int(d[2])-1 || int(b[2])==int(d[2])+1)cout<<'1';
		else cout<<'0';
	}
	return 0;
}
