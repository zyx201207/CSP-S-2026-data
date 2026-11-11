#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2,s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			int a=s1[2]-'A'+1,b=s2[2]-'A'+1;
			if(a==6){
				a=5;
			}if(b==6){
				b=5;
			}
			if(a<=3&&b<=3){
				cout<<1;
				if(abs(a-b)==1){
					cout<<1;
				}else{
					cout<<0;
				}
			}else if(a>3&&b>3){
				cout<<11;
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
