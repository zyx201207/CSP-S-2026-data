#include<bits/stdc++.h>
using namespace std;

int main()
{

	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	int num1=0,num2=0,num3=0,num4=0;
	
	if(c1==c2){
		num1=1;
		if(s1[0]==s2[0] and s1[1]==s2[1]){
			num2=1;
			if(s1[2]-s2[2]==1 or s1[2]-s2[2]==-1){
				num3=num4=1;
				}	
			if(s1[2]-s2[2]==2 or s1[2]-s2[2]==-2){
				num3=num4=1;
				}
				if(s1[2]=='A' and s2[2]=='C'){
					num3=1;
					num4=0;}
				if(s1[2]=='C' and s2[2]=='A'){
					num3=1;
					num4=0;}
				if(s1[2]=='D' and s2[2]=='C'){
					num3=num4=0;
				}
				if(s1[2]=='C' and s2[2]=='D'){
					num3=num4=0;
				}
		}
		
	}
	cout<<num1<<num2<<num3<<num4;

	return 0;
}
