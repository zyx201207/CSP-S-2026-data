#include <bits/stdc++.h>
using namespace std;
string c1,c2;
long long a,b,c,d;
char s1[5],s2[5];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);	
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) {
		cout<<"1";
	}
	else{
		cout<<"0000";
		return 0;
	}
	if((s1[0]==s2[0])&&(s1[1]==s2[1])){
		cout<<"1";
	}
	else{
		cout<<"000";
		return 0;
	}
	a=s1[2]-'0';
	b=s2[2]-'0';
	c=max(a,b);
	d=min(a,b);
	if((c<20&&d<20)||(c>19&&d>19)){
		cout<<"1";
		if(c-d==1){
			cout<<"1";
		}else cout<< "0";
				
	}else cout<<"00";
	return 0;
}
