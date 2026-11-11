#include<bits/stdc++.h>
using namespace std;
int a,c,b1,d1;
string b,d;
char b2,d2;
bool ans1,ans2,ans3,ans4;
void replace(){
	b1+=(b[0]-'0')*10;
	b1+=b[1]-'0';
	d1+=(d[0]-'0')*10;
	d1+=d[1]-'0';
	b2=b[2];d2=d[2];
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	replace();
	if(a==c)ans1=1;
	if(ans1==1&&b1==d1)ans2=1;
//	cout<<b2<<d2<<endl;
	if(ans1==1&&ans2==1&&
	((b2<='C'&&d2<='C')||(b2>='D'&&d2>='D')))ans3=1;
	if(ans1==1&&ans2==1&&ans3==1&&
	((b2-d2==1||d2-b2==1)||(b2=='D'&&d2=='F'||b2=='F'&&d2=='D')))
	ans4=1;
	cout<<ans1<<ans2<<ans3<<ans4;
	return 0;
}
