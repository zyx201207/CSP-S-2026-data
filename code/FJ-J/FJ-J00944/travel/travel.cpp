#include<bits/stdc++.h>
//#define int long long
using namespace std;
inline int read(){
	char c=getchar();
	int x=0,f=1;
	for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
	for(;isdigit(c);c=getchar()) x=x*10+c-'0';
	return x*f;
}
inline void write(int x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9) write(x/10);
	putchar(x%10^48);
	return;
}
string a,b;
int n,m; 
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	n=read();	 
	cin>>a;
	m=read();
	cin>>b;
	if(n==m){
		printf("1");
		if(a[0]==b[0]&&a[1]==b[1]){
			printf("1");
			if((a[2]<='C'&&b[2]<='C')||(a[2]>'C'&&b[2]>'C')){
				printf("1");
				int x=abs(a[2]-b[2]);
				if((x==1)||(a[2]=='D'&&b[2]=='F')||(a[2]=='F'&&b[2]=='D')){
					printf("1");
					return 0;
				}else printf("0");
			}else{
				printf("0");
				printf("0");
			}
		}else{
			printf("0");
			printf("0");
			printf("0");
		}
		return 0;
	}
	printf("0");
	printf("0");
	printf("0");
	printf("0");
	return 0;
}
