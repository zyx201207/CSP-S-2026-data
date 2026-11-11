#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b;
	string c,d;
	cin>>a>>c>>b>>d;
	if(a==b) cout<<"1";
	else cout<<"0";
	if(a==b&&c[0]==d[0]&&c[1]==d[1]) cout<<"1";
	else cout<<"0";
	if(a==b&&c[0]==d[0]&&c[1]==d[1]&&d[2]>'C'&&c[2]>'C') cout<<"1";
	else{
		if(a==b&&c[0]==d[0]&&c[1]==d[1]&&d[2]<'D'&&c[2]<'D') cout<<"1";
		else cout<<"0";
	}
	if(a==b&&c[0]==d[0]&&c[1]==d[1]&&c[2]+1==d[2]) cout<<"1";
	else{
		if(a==b&&c[0]==d[0]&&c[1]==d[1]&&c[2]-1==d[2]) cout<<"1";
		else cout<<"0";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
