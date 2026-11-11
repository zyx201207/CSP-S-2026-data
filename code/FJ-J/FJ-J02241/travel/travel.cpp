#include<bits/stdc++.h>
using namespace std;
inline void read(string &x){
	x="";
	char c=getchar();
	while((c>='0'&&c<='9')||(c>='A'&&c<='F')){
		x+=c;
		c=getchar();
	}
	return;
}
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	read(c1);
	read(s1);
	read(c2);
	read(s2);
	if(c1!=c2){
		cout<<"0000\n";
	}else{
		cout<<1;
		int g1=(s1[0]-'0')*10+(s1[1]-'0');
		int g2=(s2[0]-'0')*10+(s2[1]-'0');
		if(g1!=g2){
			cout<<"000\n";
		}else{
			cout<<1;
			char u1=s1[2];
			char u2=s2[2];
			if((u1<='C'&&u2<='C')||(u1>='D'&&u2>='D')){
				cout<<1;
				if(u1>='D'){
					cout<<"1\n";
				}else if(u1=='B'||u2=='B'){
					cout<<"1\n";
				}else{
					cout<<"0\n";
				}
			}else{
				cout<<"00\n";
			}
		}
	}
	return 0;
}