#include <bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>s1>>s2;
	char a=c2[2];
	char b=s2[2];
	if(c1==s1){
		cout<<1;
		if(c2[0]==s2[0]&&c2[1]==s2[1]){
			cout<<1;
			if(((a>='A'&&a<='C')&&(b>='A'&&b<='C'))||((a>='D'&&a<='F')&&(b>='D'&&b<='F'))){
				cout<<1;
				if((a==b+1||a==b-1||(a=='D'&&b=='F')||(a=='F'&&b=='D'))&&!((a=='C'&&b=='D')||(a=='D'&&b=='C'))){
					cout<<1;
				}else
					cout<<0;
			}else
				cout<<0<<0;
		}else
			cout<<0<<0<<0;
	}else
		cout<<0<<0<<0<<0;
	return 0;
}
