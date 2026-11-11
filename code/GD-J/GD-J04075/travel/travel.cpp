#include<bits/stdc++.h>
using namespace std;
string c1,c2;
string s1,s2;
bool sa(string s1,string s2){
	char a=s1[2],b=s2[2];
	if((a>='A'&&a<='C'&&b>='A'&&b<='C')||((a>='D'&&a<='F'&&b>='D'&&b<='F'))) return true;
	return false;
}
bool na(string s1,string s2){
	char a=s1[2],b=s2[2];
	if(abs(a-b)==1||((a=='D'&&b=='F')||(a=='F'&&b=='D'))) return true;
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			if(sa(s1,s2)){
				cout<<1;
				if(na(s1,s2)){
					cout<<1;
				}else cout<<0;
			}else cout<<0<<0;
		}else cout<<0<<0<<0;
	}else cout<<0<<0<<0<<0;
	return 0;
}

