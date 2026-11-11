#include<bits/stdc++.h>
#define ll long long
using namespace std;
char ch1,ch2;
ll a1,a2,c1,c2;
string ss1,ss2;
bool f1,f2,f3,f4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
//	freopen("travel5.in","r",stdin);
//	freopen("travel5.out","w",stdout);
	
	cin>>a1>>ss1;
	cin>>a2>>ss2;
	ch1=ss1[2];ch2=ss2[2];
	c1=(ss1[0]-'0')*10+(ss1[1]-'0');
	c2=(ss2[0]-'0')*10+(ss2[1]-'0');
	if(a1==a2) f1=1;
	if(f1&&c1==c2) f2=1;
	if(f2&&((ch1<='C'&&ch2<='C')||(ch1>='D'&&ch2>='D'))) f3=1;
	if(f3&&abs(ch2-ch1)==1) f4=1;
	cout<<f1<<f2<<f3<<f4;
	return 0;
}
