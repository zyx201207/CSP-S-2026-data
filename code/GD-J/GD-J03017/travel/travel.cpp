#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c1,c2;
string s1,s2,ans;
bool p1,p2,p3;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	string x,r;//x是x的排，r是r的排 
	if(c1==c2){
		ans+='1';
		p1=1;
	} 
	else ans+='0';
	x+=s1[0];
	x+=s1[1];
	r+=s2[0];
	r+=s2[1];
	if(p1==1&&x==r){
		ans+='1';
		p2=1;
	} 
	else ans+='0';
	if(p1==1&&p2==1&&((s1[2]>='A'&&s1[2]<='C')&&(s2[2]>='A'&&s2[2]<='C'))||((s1[2]>='D'&&s1[2]<='F')&&(s2[2]>='D'&&s2[2]<='F'))){
		ans+='1';
		p3=1;
	} 
	else ans+='0';
	char tmp=s1[2];
	if(p1==1&&p2==1&&tmp=='C'){
		//cout<<11111111111111<<endl;
		if(p3==1&&s2[2]=='B'){
			ans+='1';
			p1=1;
		} 
		else ans+='0';
	}else if(p1==1&&p2==1&&p3==1&&tmp=='D'){
		if(p3==1&&s2[2]=='F') ans+='1';
		else ans+='0';
	}else{
		//cout<<11111111111111<<endl;
		if((p1==1&&p2==1&&p3==1)&&char(tmp-1)==s2[2]||char(tmp+1)==s2[2]) ans+='1';
		else ans+='0';
	}
	cout<<ans;
	return 0;
} 
