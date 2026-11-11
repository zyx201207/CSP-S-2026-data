#include<bits/stdc++.h>
using namespace std;
#define int long long
string s1,s2,s3,s4;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	int a=(s1[0]-'0')*10+(s1[1]-'0'),b=(s2[0]-'0')*10+(s2[1]-'0'),c=(s3[0]-'0')*10+(s3[1]-'0'),d=(s4[0]-'0')*10+(s4[1]-'0');
	char e=s2[2],f=s4[2];
	if(a==c){
		cout<<1;
		if(b==d){
			cout<<1;
			if(('A'<=e&&e<='C'&&'A'<=f&&f<='C')||('D'<=e&&e<='F'&&'D'<=f&&f<='F')){
				cout<<1;
				if(abs((e-'A')-(f-'A'))==1){
					cout<<1;
				}else{
					cout<<0;
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
