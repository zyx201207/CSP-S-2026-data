#include<bits/stdc++.h>
using namespace std;
int toint(string s){
	int ans=0;
	for(int i=0;i<s.length();i++){
		ans*=10;
		ans+=s[i]-'0';
	}
	return ans;
}int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	long long c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	bool ffff=1;
	if(c1==c2)cout<<1;
	else{
		cout<<"000";
		ffff=0;
	}bool ff=0,fff=1;
	string s3=s1.substr(0,2),s4=s2.substr(0,2);
	if(ffff){
		if(s3==s4)cout<<1;
		else cout<<0;
		int f1=(s1[2]<='C'?1:0),f2=(s2[2]<='C'?1:0);
		if(f1==f2){
			ff=1;
			if(s3==s4){
				cout<<1;
				fff=0;
			}
		}
		if(fff)cout<<0;	
	}bool f=1;
	int i1=toint(s3),i2=toint(s4);
	if(s3==s4){
		if(s1[2]-1==s2[2]||s1[2]+1==s2[2]){
			if(ff==0)f=1;
			else{
				cout<<1;
				f=0;
			}
		}
	}if(f)cout<<0;
} 
