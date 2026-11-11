//GZ-J00176遵义红花岗区第四小学娄雨涵 
#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		int a=(s1[0]-'0')*10+(s1[1]-'0'),b=(s2[0]-'0')*10+(s2[1]-'0');
		if(a==b){
			cout<<"1";
			char x=s1[2],y=s2[2];
			if((x=='D'&&y=='F'||x=='F'&&y=='D')||(x=='A'&&y=='B'||x=='B'&&y=='A'||x=='A'&&y=='C'||x=='C'&&y=='A'||x=='B'&&y=='C'||x=='C'&&y=='B')){
				cout<<"1";
				if((x=='D'&&y=='F'||x=='F'&&y=='D')||(x=='A'&&y=='B'||x=='B'&&y=='A'||x=='B'&&y=='C'||x=='C'&&y=='B')){
					cout<<"1";
				}else{
					cout<<"0";
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	
	return 0;
}
