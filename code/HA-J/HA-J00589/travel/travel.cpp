#include<bits/stdc++.h>
using namespace std;
int c1,s1;
string c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>s1>>s2;
	if(c1==s1){
		cout<<1;
		if(c2[0]==s2[0]&&c2[1]==s2[1]){
			cout<<1;
		}
		else{
			cout<<0;
		}
		if((c2[0]==s2[0]&&c2[1]==s2[1])&&(((c2[2]>='A'&&c2[2]<='C')&&(s2[2]>='A'&&s2[2]<='C'))||((s2[2]>='D'&&s2[2]<='F')&&(c2[2]>='D'&&c2[2]<='F')))){
			cout<<1;
			if((c2[2]=='A'&&s2[2]=='C')||(s2[2]=='A'&&c2[2]=='C')){
				cout<<0;
			}
			else{
				cout<<1;
			}
		}
		else{
			cout<<0;
			cout<<0;
		}
	}
	else{
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
	}
	return 0;
}
