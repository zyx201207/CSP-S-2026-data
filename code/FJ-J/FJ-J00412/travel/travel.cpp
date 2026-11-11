#include<bits/stdc++.h>
using namespace std;
bool flag1,flag2,flag3,flag4;
string s1,s2,s3,s4,tmp1="",tmp2="";
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	if(s1==s3){
		flag1=true;
		tmp1=s2[0]+s2[1];
		tmp2=s4[0]+s4[1];
		if(tmp1==tmp2){
			flag2=true;
			if((s2[2]<='C'&&s4[2]<='C')||(s2[2]>='D'&&s4[2]>='D')){
				flag3=true;
				if(abs(s2[2]-s4[2])==1) flag4=true;
			}
		}
	}
	cout<<flag1<<flag2<<flag3<<flag4;
	return 0;
}