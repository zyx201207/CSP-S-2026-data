#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s1,s2,s3,s4;
	cin>>s1>>s2>>s3>>s4;
	if(s1!=s3) puts("0000");
	else{
		printf("1");
		int k1=(s2[0]-'0')*10+s2[1]-'0';
		int k2=(s4[0]-'0')*10+s4[1]-'0';
		if(k1!=k2) puts("000");
		else{ 
			printf("1");
			int ch1=s2[2]-'A',ch2=s4[2]-'A';
			ch1=(ch1==5?4:ch1);
			ch2=(ch2==5?4:ch2);
			if((ch1<=2&&ch2<=2)||(ch1>=3&&ch2>=3)){
				printf("1");
				if(abs(ch1-ch2)==1) puts("1");
				else puts("0");
			}
			else puts("00");
		}
	}
	return 0;
}
