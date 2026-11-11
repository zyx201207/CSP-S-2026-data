#include<bits/stdc++.h>
using namespace std;
int len1,len2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
	}
	else{
		cout<<"1";
		if(s1.substr(0,2)!=s2.substr(0,2)){
			cout<<"000";
		}
		else{
			cout<<"1";
			len1=s1.size();
			len2=s2.size();
			char a=s1[len1-1];
			char b=s2[len2-1];
			if((a>='D'&&a<='F')&&(b>='D'&&b<='F')){
				cout<<"11";
			}
			else if((a>='A'&&a<='C')&&(b>='A'&&b<='C')){
				cout<<"1";
				if(abs(int(a-b))>1){
					cout<<"0";
				}
				else{
					cout<<"1";
				}
			}
			else{
				cout<<"00";
			}
		}
	}
	return 0;
}
