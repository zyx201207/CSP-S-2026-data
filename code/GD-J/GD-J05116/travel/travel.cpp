#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<"1";
		int a=int(s1[0]-'0')*10+int(s1[1]-'0');
		int b=int(s2[0]-'0')*10+int(s2[1]-'0');
//		cout<<a<<" "<<b;
		if(a==b){
			cout<<"1";
			char x=s1[2],y=s2[2];
			bool f1=0,f2=0;
			if(x>='A'&&x<='C'&&y>='A'&&y<='C') f1=1;
			if(x>='D'&&x<='F'&&y>='D'&&y<='D') f2=1;
			if(f1==1||f2==1){
				cout<<"1";
				if(f1==1){
					if(((x=='C'||x=='A')&&y=='B')||(x=='B'&&(y=='A'||y=='C'))){
						cout<<"1";
					}else{
						cout<<"0";
					}
				}else if(f2==1){
					if((x=='D'&&y=='F')||(x=='F'&&y=='D')){
						cout<<"1";
					}else{
						cout<<"0";
					}
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}
	else cout<<"0000";
	
	return 0;
}
//02 01A 02 01B
//02 01C 02 01A
//02 01C 02 01D
//02 02B 02 01A
//02 01A 03 01A
