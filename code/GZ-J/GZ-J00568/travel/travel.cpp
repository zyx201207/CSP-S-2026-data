//GZ-J00568 遵义市第四初级中学 罗俊毅 
#include<iostream>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d,e,f;
	char g,h;
	cin>>a>>b>>c>>d;
	e=b.substr(0,2);
	f=d.substr(0,2);
	g=b[2];
	h=d[2];
	if(a==c)printf("%s","1");
	else{
		printf("%s","0000");
		return 0;
	}
	if(e==f)printf("%s","1");
	else{
		printf("%s","000");
		return 0;
	}
	bool flag1=(g>='A' && g<='C');
	bool flag2=(h>='A' && h<='C');
	if(!(flag1^flag2)){
		printf("%s","1");
	}
	else{
		printf("%s","00");
		return 0;
	}
	if(g==h+1 || h==g+1)printf("%s","1");
	else printf("%s","0");
	return 0;
}
