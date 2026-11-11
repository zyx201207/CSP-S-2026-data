#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		string x=s1.substr(0,2),y=s2.substr(0,2);
		if(x==y){
			cout<<1;
			char a=s1[s1.size()-1],b=s2[s2.size()-1];
			if(!((a<='C'&&b>='D')||(a>='D'&&b<='C'))){
				cout<<1;
				if(abs((int)a-(int)b)==1){
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
