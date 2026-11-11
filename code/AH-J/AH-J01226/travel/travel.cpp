#include <bits/stdc++.h>
using namespace std;
char roadleft[3]={'A','B','C'};
char roadright[2]={'D','F'};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int flag1=0,flag2=0,flag3=0,flag4=0;
	string c1;
	string s1;
	string c2;
	string s2;
	cin>>c1>>s1>>c2>>s2;
	int count1,count2;
	int pai1=10*s1[0]+s1[1];
	int pai2=10*s2[0]+s2[1];
	char zimu1=s1[2];
	char zimu2=s2[2];
	if(c1==c2){
		flag1=1;
		if(pai1==pai2){
			flag2=1;
			if(zimu1=='A'||zimu1=='B'||zimu1=='C'){
				if(zimu2=='A'||zimu2=='B'||zimu2=='C'){
					flag3=1;
					for(int i=0;i<3;i++){
						if(zimu1==roadleft[i]){
							count1=i;
						}
					}
					for(int j=0;j<3;j++){
						if(zimu2==roadleft[j]){
							count2=j;
						}
					}
					if(count1-count2==1||count2-count1==1||count1==count2){
						flag4=1;
					}
				}
			}else if(zimu1=='D'||zimu1=='F'){
				if(zimu2=='D'||zimu2=='F'){
					flag3=1;
					flag4=1;
				}
			}
		}
	}
	cout<<flag1<<flag2<<flag3<<flag4;
	return 0;
}
