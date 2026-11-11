#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char a1,a2,a3,a4,a5,b1,b2,b3,b4,b5;
	int n1=0,n2=0,n3=0,n4=0;
	scanf("%c%c %c%c%c %c%c %c%c%c",&a1,&a2,&a3,&a4,&a5,&b1,&b2,&b3,&b4,&b5);
	if(a1==b1&&a2==b2){
		n1=1;
	}
	if(a1==b1&&a2==b2&&a3==b3&&a4==b4){
		n2=1;
	}
	if(a1==b1&&a2==b2&&a3==b3&&a4==b4&&((a5<'D'&&b5<'D')||(a5>'C'&&b5>'C'))){
		n3=1;
	}
	if(a1==b1&&a2==b2&&a3==b3&&a4==b4){
		if(a5<'C'&&b5<'C'){
			n4=1;
		}else if(a5>'D'&&b5>'D'&&(a5=='B'||b5=='B')){
			n4=1;
		}
	}
	printf("%d%d%d%d",n1,n2,n3,n4);
	return 0;
}
