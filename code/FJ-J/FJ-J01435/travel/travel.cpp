#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	bool f1=c1==c2,f2=f1&&s1.substr(0,2)==s2.substr(0,2),f3=f2&&((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C')),f4=f2&&(abs(s1[2]-s2[2])==1);
	printf("%d%d%d%d",f1,f2,f3,f4);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
