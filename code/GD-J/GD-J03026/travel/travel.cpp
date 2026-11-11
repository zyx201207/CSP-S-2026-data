#include<bits/stdc++.h>
using namespace std;
#define int long long
string s1,s2,s3,s4;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	int o1=0,o2=0,o3=0,o4=0;
	if(s1==s3){
		cout<<1;
		o1=1;
	}
	else{
		cout<<0;
	}
	int x=(s2[0]-'0')*10+(s2[1]-'0'),y=(s4[0]-'0')*10+(s4[1]-'0');
	if(x==y&&o1==1){
		cout<<1;
		o2=1;
	}
	else{
		cout<<0;
	}
	int i=s2[2]-'A'+1,j=s4[2]-'A'+1;
	if(o2==1&&((i<=3&&j<=3)||(i>3&&j>3))){
		cout<<1;
		o3=1;
	}
	else{
		cout<<0;
	}
	if(i<j){
		swap(i,j);
	}
	if(o3==1&&i-j==1&&(i!=4||j!=3)){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
} 
