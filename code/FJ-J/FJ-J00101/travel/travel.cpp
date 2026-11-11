#include<bits/stdc++.h>
using namespace std;
#define ll long long

string c1,s1,c2,s2;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		printf("1");
		string p1=s1.substr(0,2),p2=s2.substr(0,2);
		char st1=s1[2],st2=s2[2];
		if(p1==p2){
			printf("1");
			int sd1=st1-'C',sd2=st2-'C';
			if((sd1<=0&&sd2<=0)||(sd1>0&&sd2>0)){
				printf("1");
				if(abs(sd1-sd2)==1){
					printf("1");
				}else{
					printf("0");
				}
			}else{
				printf("00");
			}
		}else{
			printf("000");
		}
	}else{
		printf("0000");
	}
	return 0;
} 
