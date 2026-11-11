#include<bits/stdc++.h>
using namespace std;
string a,b,x,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>x>>y;
	if(a==x) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(b[0]==y[0]&&b[1]==y[1])
	    cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if((b[2]>='D'&&y[2]>='D')||(b[2]<='C'&&y[2]<='C'))
	    cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	if(abs(b[2]-y[2])==1||b[2]>='D')
	    cout<<1;
	else cout<<0;
	return 0;
} 
