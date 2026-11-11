#include<bits/stdc++.h>
#define int long long
using namespace std; 
string c1,c2,s1,s2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int flag3=0;
	if(c1!=c2){
		cout<<0;
	}else{
		cout<<1;
		flag3=1;
	}
	int ss1=(s1[0]-'0')*10+(s1[1]-'0');
	int ss2=(s2[0]-'0')*10+(s2[1]-'0');
	int flag1=0,flag2=0;
	if((ss1!=ss2)||(flag3==0)){
		cout<<0;
	}else{
		cout<<1;
		flag1=1;
	}
	int a1=s1[2]-'A'+1,a2=s2[2]-'A'+1;
	
	if(((a1<=3&&a2<=3)||(a1>3&&a2>3))&&(flag1==1)){
		cout<<1;
		flag2=1;
	}else{
		cout<<0;
	}
	if((flag1==1)&&(flag2==1)&&(abs(a2-a1)==1)){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
