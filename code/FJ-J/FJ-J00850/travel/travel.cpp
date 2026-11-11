#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int w1,w2;
bool f=0,f1=0,f2=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3){cout<<1;f=1;}
	else cout<<0;
	w1=(int(s2[0])-48)*10+(int(s2[1])-48);
	w2=(int(s4[0])-48)*10+(int(s4[1])-48);
	if(w1==w2&&f){cout<<1;f1=1;}
	else cout<<0;
	if(f1&&(s2[2]>='A'&&s2[2]<='C'&&s4[2]>='A'&&s4[2]<='C')||(s2[2]>='D'&&s2[2]<='F'&&s4[2]>='D'&&s4[2]<='F')&&s2[2]!=s4[2]) {cout<<1;f2=1;}
	else cout<<0;
	if((abs(int(s2[2])-int(s4[2]))==1)&&f2) cout<<1;
	else cout<<0;
	return 0;
}
