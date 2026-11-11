#include<bits/stdc++.h>
using namespace std;
string a,b,c,d,sum,ab,cd;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>a>>b>>c>>d;
	char e=b[2],f=d[2];
	ab=(b[0]+b[1]);
	cd=(d[0]+d[1]);
	if(a==c)cout<<"1";
	else cout<<"0";
	if(ab==cd&&a==c)cout<<"1";
	else cout<<"0";
	if(ab==cd&&a==c&&((e=='D'&&f=='F')||(f=='D'&&e=='F')||(e!='D'&&f!='F'&&f!='D'&&e!='F')))cout<<"1";
	else cout<<"0";
	if(ab==cd&&a==c&&((e=='D'&&f=='F')||(f=='D'&&e=='F')||(e!='D'&&f!='F'&&f!='D'&&e!='F'))&&((e+1==f&&e!='F')||(e-1==f&&e!='A')))cout<<"1";
	else cout<<"0";
	return 0;
} 
