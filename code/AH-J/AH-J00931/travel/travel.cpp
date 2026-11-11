#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	bool f=0;
	cin>>a>>b>>c>>d;
	if(a==c) cout<<1;
	else {
		cout<<"0000";
		return 0;
	}
	if(b[0]==d[0]&&b[1]==d[1]) cout<<1;
	else{
		cout<<"000";
		return 0;
		
	}
	if((b[2]<='C'&&d[2]<='C')||(b[2]>='D'&&d[2]>='D')) {
		cout<<1; f=1;
	}
	else cout<<0;
	if(f==1&&abs(int(b[2]-d[2]))==1) cout<<1;
	else cout<<0;
	return 0;
}
