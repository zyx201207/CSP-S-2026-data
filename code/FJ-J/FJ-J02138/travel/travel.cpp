#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		if(s1[0]*10+s1[1]==s2[0]*10+s2[1]){
			cout<<1;
			if(s1[2]>'C'&&s2[2]>'C'||s1[2]<'D'&&s2[2]<'D'){
				cout<<1;
				char t=s1[2]+1,y=s2[2]+1;
				if(t==s2[2]||y==s1[2]){
					cout<<1;
					return 0;
				}else{
					cout<<0;
					return 0;
				}
			}else{
				cout<<0<<0;
				return 0;
			}
		}else{
			cout<<0<<0<<0;
			return 0;
		}
	}else{
		cout<<0<<0<<0<<0;
		return 0;
	}
} 
