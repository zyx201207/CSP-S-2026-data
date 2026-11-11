#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string s,s1,ans;
	cin>>a>>s>>b>>s1;
	int x=(s[0]-'0')*10+(s[1]-'0');
	int y=(s1[0]-'0')*10+(s1[1]-'0');
	int x_=s[2]-65,y_=s1[2]-65;
	if(a!=b) ans="000";
	else{
		ans+='1';
		if(x==y){
			ans+='1';
			if(s1[2]>='D'&&s[2]<='C'||s1[2]<='C'&&s[2]>='D'){
				ans+='0';
			}else ans+='1';
		}
		else ans+="00";
	}
	if(abs(x_-y_==1	&&!(x_==3&&y_==4||x_==4&&y_==3))&&x==y) ans+='1';
	else ans+='0';
	cout<<ans;
	return 0;
}

