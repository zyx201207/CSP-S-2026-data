#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a==c) cout<<"1";
	else cout<<"0";
	if(a==c && b[1]==d[1]) cout<<"1";
	else cout<<"0";
	if(a==c && b[1]==d[1] && ((b[2]>='D' && d[2]>='D') || (b[2]<='C' && d[2]<='C'))) cout<<"1";
	else cout<<"0";
	if(a==c && b[1]==d[1] && (b[2]>='D' && d[2]>='D') && abs(int(b[2])-int(d[2]))==2) cout<<"1";
	else if(a==c && b[1]==d[1] && (b[2]<='C' && d[2]<='C') && abs(int(b[2])-int(d[2]))==1) cout<<"1";
	else cout<<"0";
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
