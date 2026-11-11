#include<bits/stdc++.h>
using namespace std;
int a,c;
string b,d;
bool f;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>a>>b>>c>>d;
	f=1;
	if(a==c) cout<<1;
	else{
		cout<<0;
		f=0;
	}
	if(b[0]==d[0]&&b[1]==d[1]&&f) 
		cout<<1;
	else{
		cout<<0;
		f=0;
	}
	if(b[2]>='A'&&b[2]<='C'&&d[2]>='A'&&d[2]<='C'&&f)
		cout<<1;
	else if(b[2]>='D'&&b[2]<='F'&&d[2]>='D'&&d[2]<='F'&&f)
		cout<<1;
	else{
		cout<<0;
		f=0;
	}
	if((b[2]==d[2]+1||b[2]==d[2]-1)&&f)
		cout<<1;
	else cout<<0;
	return 0;
}
