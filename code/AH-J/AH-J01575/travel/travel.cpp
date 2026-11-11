/*
游记-T1
8:30:开考，密码老师给报成Trick||Trict!了 ，吃力一会，终于打开了
8:40：开始看题，第一题很简单，只是用sscanf（打成了sprintf的蒟蒻）然后判断就可以了
9：00：第一题写完了，看看下一题 
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int Rr,Rs,Xr,Xs;
char Rw,Xw;
char s1[4],s2[4],s3[4],s4[4];
signed main(){
	freopen("travel.in","r",stdin); 
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	sscanf(s1,"%d",&Rr);
	sscanf(s2,"%d%c",&Rs,&Rw);
	sscanf(s3,"%d",&Xr);
	sscanf(s4,"%d%c",&Xs,&Xw);
	if(Rr==Xr)
		cout<<"1";
	else{
		cout<<"0000";	
		return 0;
	}
	if(Rs==Xs)
		cout<<"1";
	else{
		cout<<"000";	
		return 0;
	}
	if(Rw=='D'||Rw=='F')Rw+=2;
	if(Xw=='D'||Xw=='F')Xw+=2;
	if(abs(Rw-Xw)<=2)
		cout<<"1";
	else{
		cout<<"00";	
		return 0;
	}
	if(abs(Rw-Xw)==1)
		cout<<"1";
	else{
		cout<<"0";	
		return 0;
	}
	return 0;
} 
//Trick||Treat!
