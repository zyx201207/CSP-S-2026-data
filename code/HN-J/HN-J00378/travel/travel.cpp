#include<bits/stdc++.h>
using namespace std;
char a[5],b[5],c[5],d[5];
int main(){
	freopen("travel.in","r",stdin);freopen("travel.out","w",stdout);
	cin>>a[1]>>a[2]>>b[1]>>b[2]>>b[3]>>c[1]>>c[2]>>d[1]>>d[2]>>d[3];
	if(a[2]==c[2]&&a[1]==c[1])
	{
		if(b[1]==d[1]&&b[2]==d[2])
		{
			if((b[3]=='A'&&d[3]=='B')||(b[3]=='A'&&d[3]=='C')||(b[3]=='B'&&d[3]=='C')||(b[3]=='D'&&d[3]=='F')||(b[3]=='F'&&d[3]=='D')||(b[3]=='C'&&d[3]=='B')||(b[3]=='C'&&d[3]=='A')||(b[3]=='B'&&d[3]=='A'))
			{
				if((b[3]=='A'&&d[3]=='B')||(b[3]=='B'&&d[3]=='C')||(b[3]=='D'&&d[3]=='F')||(b[3]=='F'&&d[3]=='D')||(b[3]=='C'&&d[3]=='B')||(b[3]=='B'&&d[3]=='A'))
				printf("1111");
				else printf("1110");
			}
			else printf("1100");
		}
		else printf("1000");
	}
	else printf("0000");
	fclose(stdin);fclose(stdout);
	return 0;
}
