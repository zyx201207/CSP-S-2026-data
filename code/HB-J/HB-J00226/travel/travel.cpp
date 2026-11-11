#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);
string a,b,c,d;
cin>>a>>b>>c>>d;
if(a[0]==c[0]&&a[1]==c[1]){
	printf("1");
	if(b[0]==d[0]&&b[1]==d[1]){
	printf("1");
	if((b[2]<='C'&&b[2]>='A'&&d[2]<='C'&&d[2]>='A')||(b[2]<='F'&&b[2]>='D'&&d[2]<='F'&&d[2]>='D')){
	printf("1");
	if(b[2]+1==d[2]||b[2]-1==d[2]){
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

fclose(stdin);
fclose(stdout);
return 0;
}
