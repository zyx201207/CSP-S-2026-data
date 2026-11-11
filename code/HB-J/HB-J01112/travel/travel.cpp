#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int a=1,b=1,c=0,d=1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	for(int i=0;i<2;i++){
		if(s1[i]!=s3[i]){
			a=0,b=0,d=0;
			cout<<a<<b<<c<<d;
			return 0;
		}
	}
	for(int i=0;i<2;i++){
		if(s2[i]!=s4[i]){
			b=0,d=0;
			cout<<a<<b<<c<<d;
			return 0;
		}
	}
	if((s2[2]<'D'&&s4[2]<'D')||(s2[2]>'C'&&s4[2]>'C')){
		c=1;
	}else{
		d=0;
		cout<<a<<b<<c<<d;
		return 0;
	}
	if(abs(int(s2[2])-int(s4[2]))!=1){
		d=0;
	}
	cout<<a<<b<<c<<d;
	return 0;
}
