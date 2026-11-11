#include<bits/stdc++.h>
using namespace std;
string s1,s2,t1,t2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>t1>>s2>>t2;
	if(s1==s2){
		cout<<1;
		if(t1[0]==t2[0]&&t1[1]==t2[1]){
			cout<<1;
			char c=max(t1[2],t2[2]),a=min(t1[2],t2[2]);
			if((a=='A'&&c=='C')||(c-a<=1&&!(c=='D'&&a=='C'))){
				cout<<1;
				if(a=='A'&&c=='C')cout<<0;
				else cout<<1;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else {
		cout<<"0000";
	}	
	return 0;
}
