#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		string a=s1.substr(0,2),b=s2.substr(0,2);
		if(a==b){
			cout<<"1";
			if((s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')){
				cout<<"1";
				if(abs(s1[2]-s2[2])==1){
					cout<<"1\n";
				}else{
					cout<<"0\n";
				}
			}else if((s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F')){
				cout<<"11\n";
			}else{
				cout<<"00\n";
			}
		}else{
			cout<<"000\n";
		}
	}else{
		cout<<"0000\n";
	}
}
