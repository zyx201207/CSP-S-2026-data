#include<bits/stdc++.h>
using namespace std;
string s1,c1,s2,c2;
int k1,k2,k3,k4;
int tc,tc2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		k1=1;
	}
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]){
		k2=1;
	}
	if(s1[2]<='C'&&s1[2]>='A'&&s2[2]<='C'&&s2[2]>='A'){
		tc=1;
	}
	if(s1[2]<='F'&&s1[2]>='D'&&s2[2]<='F'&&s2[2]>='D'){
		tc2=1;
	}
	if(k1==1&&k2==1&&(tc==1||tc2==1)){
		k3=1;
	}
	if(tc2==1&&k1==1&&k2==1&&k3==1){
		k4=1;
	}else if(tc==1&&k1==1&&k2==1&&k3==1&&(s1[2]+1==s2[2]||s1[2]-1==s2[2])){
		k4=1;
	}
	cout<<k1<<k2<<k3<<k4;
	return 0;
} 
