#include<bits/stdc++.h>
using namespace std;
string c,s,cc,ss;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>cc>>ss;
	if(c==cc){
		cout<<"1";
	}
	else{
		cout<<"0000";
		return 0;
	}
	if(s[0]==ss[0]&&s[1]==ss[1]){
		cout<<"1";
	}
	else{
		cout<<"000"; 
		return 0;
	}
	if((s[2]<='C'&&ss[2]<='C')||(s[2]>='D'&&ss[2]>='D')){
		cout<<"1";
	}
	else{
		cout<<"00";
		return 0;
	}
	char a=s[2],b=ss[2];
	if(a>b)swap(a,b);
	if(b==a+1)cout<<"1";
	else cout<<0;
	return 0;
}

