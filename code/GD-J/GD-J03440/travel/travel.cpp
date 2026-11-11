#include<bits/stdc++.h>
using namespace std;
string s,t;
string s1,t1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s>>t>>s1>>t1;
	if(s==s1){
		cout<<1;
		string a={t[0],t[1]},a1={t1[0],t1[1]};
		if(a==a1){
			cout<<1;
			char b=t[2],b1=t1[2];
			if((b<'D'&&b1<'D')||(b>'C'&&b1>'C')){
				cout<<1;
				if(abs(int(b)-int(b1))==1) cout<<1;
				else cout<<0;
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
} 
