#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int c1,c2;
int s1,ss1,s2,ss2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,a2;
	cin>>c1>>a1>>c2>>a2;
	s1=(a1[0]-'0')*10+(a1[1]-'0');
	ss1=a1[2]-'A';
	s2=(a2[0]-'0')*10+(a2[1]-'0');
	ss2=a2[2]-'A';
	if(c1==c2){
		cout<<1;
	}else{
		cout<<0;
	}
	if(c1==c2&&s1==s2){
		cout<<1; 
	}else{
		cout<<0;
	}
	if(c1==c2&&s1==s2&&(((ss1<=2)&&(ss2<=2))||((ss1>=3)&&(ss2>=3)))){
		cout<<1;
	}else{
		cout<<0;
	}
	if(c1==c2&&s1==s2&&((ss1==0&&ss2==1)||(ss1==1&&ss2==0)||(ss1==1&&ss2==2)||(ss1==2&&ss2==1)||(ss1==3&&ss2==5)||(ss1==5&&ss2==3))){
		cout<<1;
	}else{
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
