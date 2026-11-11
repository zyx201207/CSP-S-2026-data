#include<bits/stdc++.h> 
using namespace std;
int co,ct,oo,ot;
string so,st;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>co>>so>>ct>>st;
	oo=(so[0]-48)*10+so[1]-48;
	ot=(st[0]-48)*10+st[1]-48;
	if(co==ct){
		printf("1");
		if(oo==ot){
			printf("1");
			if((so[2]=='D'&&st[2]=='F')||(so[2]=='F'&&st[2]=='D')||(so[2]!='F'&&so[2]!='D'&&st[2]!='F'&&st[2]!='D')){
				printf("1");
				if(abs(int(so[2]-st[2]))==1){
					printf("1");
					return 0;
				}
				else{
					printf("0");
					return 0;
				}
			}
			else{
				printf("00");
			    return 0;
			}
		}
		else{
			printf("000");
			return 0;
		}
	}
	else printf("0000");
	return 0;
}
