#include<bits/stdc++.h>
using namespace std;
string a,b,x,y,p,q;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>b>>a>>y>>x;
	if(b==y)cout<<'1';
	else{
		cout<<"0000";
		return 0;
	}
	p=a[0]+a[1],q=x[0]+x[1];
	if(p==q)cout<<'1';
	else{
		cout<<"000";
		return 0;
	}
	if(((x[2]=='A'||x[2]=='B'||x[2]=='C')&&(a[2]=='A'||a[2]=='B'||a[2]=='C'))||((x[2]=='D'||x[2]=='F')&&(a[2]=='D'||a[2]=='F')))cout<<'1';
	else{
		cout<<"00";
		return 0;
	}
	if((x[2]=='A'&&a[2]=='B')||(x[2]=='B'&&a[2]=='C')||(x[2]=='D'&&a[2]=='F')||(a[2]=='A'&&x[2]=='B')||(a[2]=='B'&&x[2]=='C')||(a[2]=='D'&&x[2]=='F'))cout<<'1';
	else cout<<'0';
	fclose(stdin);
	fclose(stdout);
	return 0;
}
