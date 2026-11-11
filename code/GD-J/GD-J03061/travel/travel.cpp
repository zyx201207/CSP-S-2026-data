#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin.tie(0);cout.tie(0);
	int a=0,b=0,c=0;
	cin>>c1>>s1>>c2>>s2;
	if(int(c1[0])==int(c2[0])&&int(c1[1])==int(c2[1])){
		cout<<"1";
		c=1;
	}else cout<<"0";
	if(c==1&&int(s1[0])==int(s2[0])&&int(s1[1])==int(s2[1])){
		cout<<"1";
		b=1;
	}else cout<<"0";
	if(b==1&&int(s1[2]-'A'+1)<=3&&int(s2[2]-'A'+1)<=3||int(s1[2]-'A'+1)>=4&&int(s2[2]-'A'+1)>=4){
		cout<<"1";
		a=1;
	}else cout<<"0";
	if(a==1&&abs(int(s1[2]-'A'+1)-int(s2[2]-'A'+1))==1||int(s1[2])=='D'&&int(s2[2])=='F'||int(s1[2])=='F'&&int(s2[2])=='D'){
		cout<<1;
	}else cout<<"0";
	return 0;
}
