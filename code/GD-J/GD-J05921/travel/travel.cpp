#include<bits/stdc++.h>
using namespace std;
int main(){
freopen("travel.in","r",stdin);
freopen("treval.out","w",stdout);
	int k1=0,k2=0,k3=0,k4=0;
	string a,a1,b,b1;
	cin>>a>>a1>>b>>b1;
int f1=(a1[0]-'0')+(a1[1]-'0');
int f2=(b1[0]-'0')+(b1[1]-'0');
int f3=a1[2]-'A'+1;
int f4=b1[2]-'A'+1;
if(a==b)k1=1;
if(f1==f2&&k1==1)k2=1;
if(((f3>=4&&f4>=4)||(f3<=3&&f4<=3))&&k2==1)k3=1;
if(k3==1&&(f3-f4==1||f4-f3==1))k4=1;
cout<<k1<<k2<<k3<<k4;
return 0;
}
