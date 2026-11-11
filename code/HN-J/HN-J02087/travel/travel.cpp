#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
bool f1,f2,f3,f4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	f1=!(c1-c2);
	f2=f1&&(s1[0]==s2[0]&&s1[1]==s2[1]);
	f3=f2&&((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s2[2]>='D'));
	f4=f3&&(((s1[2]<='C'&&s2[2]<='C')&&abs(s1[2]-s2[2])==1)||(s1[2]>='D'&&s2[2]>='D'));
	cout<<f1<<f2<<f3<<f4;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
