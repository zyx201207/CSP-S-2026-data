#include<bits/stdc++.h>
using namespace std;
int a,b;
bool c,d,e;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	a=(c1[0]-'0')*10+(c1[1]-'0');
	b=(c2[0]-'0')*10+(c2[1]-'0');
	if(a==b){
		cout<<"1";
		c=1;
	}
	else cout<<"0";
	a=(s1[0]-'0')*10+(s1[1]-'0');
	b=(s2[0]-'0')*10+(s2[1]-'0');
	if(a==b){
		cout<<"1";
		d=1;
		if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
			if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
				cout<<"1";
				e=1;
			}
			else cout<<"0";
		}else{
			if(s2[2]=='D'||s2[2]=='F'){
				cout<<"1";
				e=1;
			}
			else cout<<"0";
		}
	}else cout<<"00";
	if(c&&d&&e){
		if(s1[2]-'0'+1==s2[2]||s1[2]-'0'-1==s2[2]) cout<<"1";
		else cout<<"0";
    }
	else cout<<"0";
	return 0;
}