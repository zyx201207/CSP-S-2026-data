#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2) cout<<"0000";
	else{
		cout<<"1";
		if(s1.substr(0,2)!=s2.substr(0,2)) cout<<"000";
		else{
			cout<<"1";
			char ch1=s1[2],ch2=s2[2];
			if((ch1<='C'&&ch2<='C')||(ch1>='D'&&ch2>='D')){
				cout<<"1";
				if(abs(int(ch1)-int(ch2))==1) cout<<"1";
				else cout<<"0";
			}
			else cout<<"00";
		}
	}
	return 0;
} 
