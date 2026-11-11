#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int a1,b1,a2,b2;
char a3,b3;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<2;++i){
		a1=a1*10+(c1[i]-'0');
		a2=a2*10+(s1[i]-'0');
		b1=b1*10+(c2[i]-'0');
		b2=b2*10+(s2[i]-'0');
	}
	a3=s1[2];b3=s2[2];
	if(a1!=b1){
		cout<<"0000";
	}else{
		cout<<"1";
		if(a2==b2){
			cout<<"1";
			if((a3<='C'&&b3<='C')||(a3>='D'&&b3>='D')){
				cout<<"1";
				if(a3+1==b3||a3-1==b3)cout<<"1";
				else cout<<"0";
			}else cout<<"00";
		}
		else cout<<"000";
	}
}
