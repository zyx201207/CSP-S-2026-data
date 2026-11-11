#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	cout<<1;
	string a=s1.substr(0,2);
	string b=s2.substr(0,2);
	if(a==b){
		cout<<1;
		char a1=s1[s1.size()-1];
		char b1=s2[s2.size()-1];
		if((a1>='A'&&a1<='C'&&b1>='A'&&b1<='C')||(a1>='D'&&a1<='E'&&b1>='D'&&b1>='E')){
			cout<<1;
			if(abs(a1-b1)==1){
					cout<<1;
			}
			else{
				cout<<0;
			}
		}else{
			cout<<"00";
			return 0;
		}
	}else{
		cout<<"000";
		return 0;
	}
	return 0;
}
