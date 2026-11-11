#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
char s3,s4;
int a,b,c,d;
int p[6]={1,1,1,0,-1,0};
int num(string s){
	int ans=0;
	for(int i=0;i<=1;i++){
		ans=ans*10+(s[i]-'0');
	}
	return ans;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	a=num(c1);
	b=num(s1);
	s3=s1[2];
	c=num(c2);
	d=num(s2);
	s4=s2[2];
	if(a==c)cout<<1;
	else cout<<0;
	if(a==c&&b==d)cout<<1;
	else cout<<0;
	if(a==c&&b==d&&p[s3-'A']==p[s4-'A'])cout<<1;
	else cout<<0;
	if(a==c&&b==d&&p[s3-'A']==p[s4-'A']){
		if(abs((int)(s3-'A')-(int)(s4-'A'))==1){
			if((s3=='C'&&s4=='D')||(s4=='C'&&s3=='D'))cout<<0;
			else cout<<1;
		}
		else cout<<0;
	}
	else cout<<0;
	return 0;
}

