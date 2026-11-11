#include<bits/stdc++.h>
using namespace std;
bool f;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		f=1;
	} 
	else cout<<0;
	string s3="",s4="";
	s3+=s1[0];
	s3+=s1[1];
	s4+=s2[0];
	s4+=s2[1];
	if(s3==s4&&f==1) cout<<1;
	else{ 
		cout<<0;
		f=0;
	}
	if(f==1&&((s1[2]>='D'&&s2[2]>='D')||(s1[2]<='C'&&s2[2]<='C'))) cout<<1;
	else{
		cout<<0;
		f=0;
	}
	if((int(s1[2])+1==int(s2[2])||int(s1[2])-1==int(s2[2])||(int(s1[2])+2==int(s2[2])&&s1[2]>='D')||(int(s1[2])-2==int(s2[2])&&s1[2]>='D'))&&f==1) cout<<1;
	else cout<<0;
	
	return 0;
}
