#include<bits/stdc++.h>
using namespace std;
#define int long long
string a,c;
string b,d;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    if(a!=c){
    	printf("0000");
	}
	else{
		printf("1");
		if(b[0]==d[0] && b[1]==d[1]){
			printf("1");
			if((b[2]-'A'<3 && d[2]-'A'<3) || (b[2]-'A'>=3 && d[2]-'A'>=3)){
				printf("1");
				if(b[2]-'A'+1==d[2]-'A' || b[2]-'A'-1==d[2]){
					printf("1");
				}
				else printf("0");
			}
			else printf("00");
		}
		else printf("000");
	}
	return 0;
}
