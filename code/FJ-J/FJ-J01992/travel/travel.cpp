#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	ll a,b,c,d;
	char c1=s2[s2.size()-1],c2=s4[s4.size()-1];
	a=(s1[0]-'0')*10+(s1[1]-'0');
	b=(s2[0]-'0')*10+(s2[1]-'0');
	c=(s3[0]-'0')*10+(s3[1]-'0');
	d=(s4[0]-'0')*10+(s4[1]-'0');
	if(a==c){
		cout<<1;
		if(b==d){
			cout<<1;
			if((c1=='D'&&c2=='E')||(c1=='E'&&c2=='D')||(c1!='D'&&c2!='E'&&c1!='E'&&c2!='D')){
				cout<<1;
				if(abs(c1-c2)==1)cout<<1;
				else cout<<0;
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
