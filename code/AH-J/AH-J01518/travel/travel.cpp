#include<stdio.h>
/*
02 01A 02 01B
1111

02 01C 02 01A
1110

02 01C 02 01D
1100

02 02B 02 01A
1000

02 01A 03 01A
0000
*/
int c1,c3,ans[5];
//string c2,c4;
char c2[15],c4[15];
//char c[1005];
int abs(int x) {
	if(x<0)return -x;
	else return x;
}
void in() { //读入
	scanf("%d",&c1);
	scanf("%s",c2);
	scanf("%d",&c3);
	scanf("%s",c4);
	return ;
}
void work() {
	if(c1==c3)
		ans[1]=1;//同一节车箱
	else return ;
	if(c2[0]+c2[1]==c4[0]+c4[1])
		ans[2]=1;//同一排
	else return ;
	if(c2[2]<='C'&&c4[2]<='C')ans[3]=1;
	else if(c2[2]>'C'&&c4[2]>'C')ans[3]=1;//同一侧
	else return ;
	if(abs(0+c2[2]-c4[2])==1&&c2[2]<='C'&&c4[2]<='C')
		ans[4]=1;
	if(abs(0+c2[2]-c4[2])==2&&c2[2]>'C'&&c4[2]>'C')
		ans[4]=1;
	return ;
}
void out() { //输出
	int i;
	for(i=1; i<=4; i++)
		printf("%d",ans[i]);
	putchar('\n');
	return ;
}
int main ()
//主程序
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	in();
	work();
	out();
	return 0;
}

