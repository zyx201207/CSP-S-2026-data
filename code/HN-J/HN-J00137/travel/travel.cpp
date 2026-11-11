#include<bits/stdc++.h>
#define int long long
using namespace std;
string x_1,y_1,x_2,y_2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> x_1 >> y_1 >> x_2 >> y_2;
	if(x_1==x_2){
		printf("1");
		if(y_1[0]==y_2[0] && y_1[1]==y_2[1]){
			printf("1");
			int ok1,ok2;
			if(y_1[2]=='A' || y_1[2]=='B' || y_1[2]=='C')ok1=1;
			else ok1=2;
			if(y_2[2]=='A' || y_2[2]=='B' || y_2[2]=='C')ok2=1;
			else ok2=2;
			if(ok1==ok2){
				printf("1");
				if(ok1==2)printf("1");
				else{
					char ch1=y_1[2],ch2=y_2[2];
					if(ch1>ch2)swap(ch1,ch2);
					if((ch1=='A' && ch2=='B') || (ch1=='B' && ch2=='C'))printf("1");
					else printf("0");
				}
			}else printf("00");
		}else printf("000");
	}else printf("0000");
	return 0;
} 
