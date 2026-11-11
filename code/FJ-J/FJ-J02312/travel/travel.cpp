#include<bits/stdc++.h>
using namespace std;
string a,b,c,d,ans;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c)ans='1';
	else{
		cout<<"0000"<<endl;
		return 0;
	}if(b[0]==d[0]&&b[1]==d[1]){
		ans+='1';
	}else{
		cout<<"1000"<<endl;
		return 0;
	}if((b[2]=='A'&&d[2]=='B')||(b[2]=='B'&&d[2]=='A')||(b[2]=='C'&&d[2]=='A')||(b[2]=='A'&&d[2]=='C')||(b[2]=='B'&&d[2]=='C')||(b[2]=='C'&&d[2]=='B')||(b[2]=='E'&&d[2]=='D')||(b[2]=='D'&&d[2]=='E')){
		ans+='1';
	}else{
		cout<<"1100"<<endl;
		return 0;
	}if(abs(int(b[2]-d[2]))==1){
		ans+='1';
	}else ans+='0';
	cout<<ans<<endl;
	return 0;
}
