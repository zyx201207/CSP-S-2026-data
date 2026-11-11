#include <bits/stdc++.h>
using namespace std;
string a,b,c,d,num1,num2;
int ans1,ans2,ans3,ans4;
bool flag1,flag2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c) ans1=1;
	else ans1=0;
	num1+=b[0];
	num1+=b[1];
	num2+=d[0];
	num2+=d[1];
	if(num1==num2 && ans1==1) ans2=1;
	else ans2=0;
	char num3,num4;
	num3=b[2],num4=d[2];
	if(num3>='A' && num3<='C') flag1=1;
	else flag1=0;
	if(num4>='A' && num4<='C') flag2=1;
	else flag2=0;
	if(flag1==flag2 && ans1==1 && ans2==1) ans3=1;
	else ans3=0;
	if((num3=='A' && num4=='B') || (num3=='B' && num4=='A')) ans4=1;
	else if((num3=='B' && num4=='C') || (num3=='C' && num4=='B')) ans4=1; 
	else if((num3=='D' && num4=='F') || (num3=='F' && num4=='D')) ans4=1;
	else ans4=0;
	if(ans3==0) ans4=0;
	cout<<ans1<<ans2<<ans3<<ans4;
	return 0;
}
