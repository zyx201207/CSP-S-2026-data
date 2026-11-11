//GZ-J00424 张云景 兴义市弘毅中学 
#include<bits/stdc++.h>
using namespace std;
char c1[10],s1[10],c2[10],s2[10],p1,p2;
long long a1,b1,a2,b2;
long long f(char x[]){
	return (x[0]-'0')*10+(x[1]-'0');
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	scanf("%s%s%s%s",&c1,&s1,&c2,&s2);
	a1=f(c1),b1=f(s1),a2=f(c2),b2=f(s2);
	p1=s1[2],p2=s2[2];
	bool m1=(a1==a2),
		 m2=(b1==b2),
		 m3=(
			(p1<='C'&&p1>='A'&&p2<='C'&&p2>='A')||
			(p1<='E'&&p1>='D'&&p2<='E'&&p2>='D')
			),
		 m4=(p1-p2==1||p2-p1==1);
	printf("%d%d%d%d\n",
			m1,
			m1&&m2,
			m1&&m2&&m3,
			m1&&m2&&m3&&m4
		  );
	return 0;
}
