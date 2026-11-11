#include<bits/stdc++.h>
using namespace std;
string x,a,y,b;
int n,m;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>x>>a>>y>>b;
	if(x==y){
		printf("1");
		n=int(a[0]-'0')*10+int(a[1]-'0');
		m=int(b[0]-'0')*10+int(b[1]-'0');
		if(n==m){
			printf("1");
			if((a[2]=='A'&&b[2]=='B')||(a[2]=='B'&&b[2]=='C')||(a[2]=='A'&&b[2]=='C')||(a[2]=='B'&&b[2]=='A')||(a[2]=='C'&&b[2]=='B')||(a[2]=='C'&&b[2]=='A')||(a[2]=='D'&&b[2]=='F')||(a[2]=='F'&&b[2]=='D')){
				printf("1");
				if(int(a[2]-b[2])==1||int(a[2]-b[2])==-1){
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

