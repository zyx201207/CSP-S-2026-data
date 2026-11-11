//GZ-J00261 遵义市第十一中学 夏琮凯  01
#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	bool b=0,b1=0,b2=0,b3=0;
	if(c1==c2&&c1!="01"&&c1!="16"){
		b=1;
		cout<<b;
	}else cout<<b;
	if(b&&s1[0]==s2[0]&&s1[1]==s2[1]){
		b1=1;
		cout<<b1;
	}else cout<<b1;
	if(b1&&((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C'))){
		b2=1;
		cout<<b2;
	}else cout<<b2;
	if(b2&&abs(s1[2]-s2[2])==1){
		b3=1;
		cout<<b3;
	}else cout<<b3;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
