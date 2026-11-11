#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d,ans="";
	cin>>a>>b>>c>>d;
	bool f=1;
	if(a==c)
		ans+='1';
	else{
		ans+='0';
		f=0;
	}
	if(b[0]==d[0]&&b[1]==d[1]&&f)
		ans+='1';
	else{
		ans+='0';
		f=0;
	}
	if(b[2]>='A'&&b[2]<='C'){
		if(d[2]>='A'&&d[2]<='C'&&f)
			ans+='1';
		else{
			ans+='0';
			f=0;
		}
	}
	else if(d[2]=='F'&&d[2]<='D'&&f)
		ans+='1';
	else{
		ans+='0';
		f=0;
	}
	if(f){
		if(char(b[2]+1)==d[2]&&b[2]!='C'){
			ans+='1';
		}
		else if(char(b[2]-1)==d[2]&&b[2]!='D'){
			ans+='1';
		}
		else{
			ans+='0';
			f=0;
		}
	}
	else
		ans+='0';
	cout<<ans;
	return 0;
}
