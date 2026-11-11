#include <bits/stdc++.h>

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	std::string s1,s2;
	std::cin>>c1>>s1>>c2>>s2;
	printf("%d",c1==c2);
	int column1=s1[0]-'0';
	column1*=10;
	column1+=s1[1]-'0';
	int column2=s2[0]-'0';
	column2*=10;
	column2+=s2[1]-'0';
	printf("%d",column1 == column2 && c1 == c2);
	char ch1,ch2;
	ch1=s1[2],ch2=s2[2];
	int flag=0;
	if(ch1 >='D' && ch2 >= 'D') flag=1;
	if(ch1 <='C' && ch2 <= 'C') flag=1;
	printf("%d",flag && column1 == column2 && c1==c2);
	if(flag && column1 == column2 && c1==c2){
		if(abs(ch1-ch2) == 1) printf("1");
		else printf("%d",0);
	}else{
		printf("0");
	}
	return 0;//02 01A 02 01B
}
