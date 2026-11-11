#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int che1=(c1[0]-'0')*10+(c1[1]-'0');
	int che2=(c2[0]-'0')*10+(c2[1]-'0');
	if(che1==che2)cout<<1;
	else{
		cout<<0<<0<<0<<0;
		return 0;
	} 
	int pai1=(s1[0]-'0')*10+(s1[1]-'0');
	int pai2=(s2[0]-'0')*10+(s2[1]-'0');
	if(pai1==pai2){
		cout<<1;
	}
	else{
		cout<<0<<0<<0;
		return 0;
	}
	int a=s1[2]-'A';
	int b=s2[2]-'A';
	if(((a>=0&&a<=2)&&(b>=0&&b<=2))||((a>=3&&a<=4)&&(b>=3&&b<=4)))cout<<1;
	else{
		cout<<0<<0;
		return 0;
	}
	if(abs(a-b)==1&&(!((a==2&&b==3)||(a==3&&b==2))))cout<<1;
	else cout<<0;
	return 0;
}
