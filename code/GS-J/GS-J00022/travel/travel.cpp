#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
string c1,c2,s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			char a=s1[2],b=s2[2];
			if((a<='C'&&b<='C')||(a>='D'&&b>='D')){
				cout<<1;
				int c,d;
				c=s1[2]-'A';
				d=s2[2]-'A';
				if(abs(c-d)==1){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<0;
				cout<<0;
			}
		}else{
			cout<<0;
			cout<<0;
			cout<<0;
		}
	}else{
		cout<<0;
		cout<<0;
		cout<<0;
		cout<<0;
	}
	return 0;
}
