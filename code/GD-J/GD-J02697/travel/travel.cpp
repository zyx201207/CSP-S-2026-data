#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	bool flag1=false,flag2=false,flag3=false,flag4=false;
	if(s1[0]==s3[0]&&s1[1]==s3[1]){
		flag1=true;
		if(s2[0]==s4[0]&&s2[1]==s4[1]){
			flag2=true;
			if(s2[2]>='A'&&s2[2]<='C'&&s4[2]>='A'&&s4[2]<='C'||s2[2]>='D'&&s2[2]<='F'&&s4[2]>='D'&&s4[2]>='F'){
				flag3=true;
				if(s2[2]-s4[2]==1||s4[2]-s2[2]==1)flag4=true;
			}
		}
	}
	cout<<flag1<<flag2<<flag3<<flag4;
	return 0;
} 
