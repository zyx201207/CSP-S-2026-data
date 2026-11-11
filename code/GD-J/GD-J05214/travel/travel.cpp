#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
string ans;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
//	cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
	if(b[2]=='A' or b[2]=='C' or b[2]=='B'){
		b[3]='l';
	}else{
		b[3]='r';
	}
	if(d[2]=='A' or d[2]=='C' or d[2]=='B'){
		d[3]='l';
	}else{
		d[3]='r';
	}
	if(a==c){
		printf("1");
		if(b[0]==d[0] and b[1]==d[1]){
			printf("1");
			if(b[3]==d[3]){
				printf("1");
				if(b[2]=='D' and d[2]=='F'){
					printf("1");
				}else if(b[2]=='F' and d[2]=='D'){
					printf("1");
				}else if(abs(b[2]-d[2])==1){
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
