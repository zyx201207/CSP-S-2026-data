#include<bits/stdc++.h>
using namespace std;
string s,s2,s3,s4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s>>s2>>s3>>s4;
	bool flag3=false;
	if(s==s3){
		cout<<1;
		flag3=true;
	}else{
		cout<<0;
	}
	bool flag=false;
	if(flag3&&s2[0]==s4[0]&&s2[1]==s4[1]){
		cout<<1;
		flag=true;
	}else{
		cout<<0;
	}
	bool flag2=false;
	if(flag&&((s2[2]<='C'&&s4[2]<='C')||(s2[2]>='D'&&s4[2]>='D'))){
		cout<<1;
		flag2=true;
	}else{
		cout<<0;
	}
	int cha=s2[2]-s4[2];
	cha=abs(cha);
	if(flag2&&cha==1){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
