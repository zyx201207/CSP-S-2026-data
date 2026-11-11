#include<iostream>
#include<cmath>
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	std::string c_r,s_r,c_x,s_x;
	std::cin>>c_r>>s_r>>c_x>>s_x;
	if(c_r==c_x)
		putchar('1');
	else
		putchar('0');
	if(c_r==c_x&&s_r[0]==s_x[0]&&s_r[1]==s_x[1])
		putchar('1');
	else
		putchar('0');
	if(c_r==c_x&&s_r[0]==s_x[0]&&s_r[1]==s_x[1]&&((s_r[2]<='C'&&s_x[2]<='C')||(s_r[2]>'C'&&s_x[2]>'C')))
		putchar('1');
	else
		putchar('0');
	if(c_r==c_x&&s_r[0]==s_x[0]&&s_r[1]==s_x[1]&&((s_r[2]<='C'&&s_x[2]<='C')||(s_r[2]>'C'&&s_x[2]>'C'))&&abs(s_r[2]-s_x[2])==1)
		putchar('1');
	else
		putchar('0');
	return 0;
}
