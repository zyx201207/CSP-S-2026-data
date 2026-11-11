#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}else{
		cout<<1;
	}
	int r1=(s1[0]-'0')*10+s1[1]-'0';
	int r2=(s2[0]-'0')*10+s2[1]-'0';
	if(r1!=r2){
		cout<<"000";
		return 0;
	}else if(r1==r2){
		cout<<1;
	}
	int a=(int)s1[2]-'A'+1;
	int b=(int)s2[2]-'A'+1;
	if((a>3&&b<=3)||(a<=3&&b>3)){
		cout<<"00";
		return 0;
	}else{
		cout<<1;
	}
	if(a+1==b||a-1==b){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}