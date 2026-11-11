//GZ-J00624 毕节梁才学校  赵纤茹
#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
string ans;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	if((s1[0]!=s3[0])||(s1[1]!=s3[1])) printf("0000");
	else{
		printf("1");
		if((s2[0]!=s4[0])||(s2[1]!=s4[1])) printf("000");
		else{
			printf("1");
			if(s2[2]<='C'&&s4[2]<='C'){
				printf("1");
				int se1=s2[2]-'A';
				int se2=s4[2]-'A';
				if((se1==se2-1)||(se1==se2+1)) printf("1");
				else printf("0");
			}else if(s2[2]>='D'&&s4[2]>='D'){
				printf("11");
			}else printf("00");
		}
	}

	return 0;
}
