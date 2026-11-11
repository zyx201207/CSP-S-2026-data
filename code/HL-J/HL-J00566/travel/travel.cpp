#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	bool a=false,b=false,c=false;
	if(c1==c2) {
		cout<<1;
		a=true;
	}else{
		cout<<0;
	}
	if(a){
		string ss1,ss2;
		ss1=s1.substr(0,2);
		ss2=s2.substr(0,2);
		if(ss1==ss2){
			cout<<1;
			b=true;
		}else{
			cout<<0;
		}
	}else{
		cout<<0;
	}
	if(b){
		if(s1[2]-'A'>=0&&s1[2]-'A'<=2){
			if(s2[2]-'A'>=0&&s2[2]-'A'<=2){
				cout<<1;
				c=true;
			}else{
				cout<<0;
			}
		}else if(s1[2]-'A'>=3&&s1[2]-'A'<=4){
			if(s2[2]-'A'>=3&&s2[2]-'A'<=4){
				cout<<1;
				c=true;
			}else{
				cout<<0;
			}
		}
	}else{
		cout<<0;
	}
	if(c){
		if(s1[2]-'A'+1==s2[2]-'A'||s1[2]-'A'==s2[2]-'A'+1){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		cout<<0;
	}
	return 0;
}
