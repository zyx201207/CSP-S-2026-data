#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
	}else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	int s3=int(s1[0]-'0')*10+int(s1[1]-'0');
	int s4=int(s2[0]-'0')*10+int(s2[1]-'0');
	int s5=int(s1[2]-'A')+1;
	int s6=int(s2[2]-'A')+1;
	if(s3==s4){
		cout<<1;
	}else{
		cout<<0<<0<<0;
		return 0;
	}
	if((s5<=3&&s6<=3)||(s5>3&&s6>3)){
		cout<<1;
	}else{
		cout<<0<<0;
		return 0;
	}
	if(abs(s5-s6)==1){
		cout<<1;
	}else{
		cout<<0;
		
	}
	return 0;
}
