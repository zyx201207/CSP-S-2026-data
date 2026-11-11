#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
int a=0,b=0,c=0,d=0;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
            if('c1'!=1&&'c1'!=16)
		{
				a=1;c=1;}
			if(s1-s2==1||s2-s1==1){
				b=1;d=1;
			}
		}else if(s1-s2==1||s2-s1==1){
				b=1;d=1;
			}
			cout<<a<<b<<c<<d;
	
	return 0;
}
