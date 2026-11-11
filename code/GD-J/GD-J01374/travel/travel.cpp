#include<bits/stdc++.h>
using namespace std;
string c1,c2;
char s1,s2,s3,ss1,ss2,ss3; 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>s2>>s3>>c2>>ss1>>ss2>>ss3;
	//同一节车厢 
	if(c1==c2){
		cout<<1;
		//同一排
		if(s1==ss1 and s2==ss2){
			cout<<1;
			if((s3<='C' and ss3<='C') or (s3>='D' and ss3>='D'))cout<<1;
			else cout<<0; 
			//是否相邻 
			if((s3+1==ss3 and s3!='C' and ss3!='D') or (ss3+1==s3 and ss3!='C' and s3!='D')) cout<<1;
			else cout<<0; 
		}else cout<<0<<0<<0; //不同排直接排除 
	}else cout<<0<<0<<0<<0;

	return 0;
}

