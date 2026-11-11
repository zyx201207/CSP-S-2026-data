 #include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
#include<stack>
#include<queue>
using namespace std;
#define ll long long
string c1,s1,c2,s2;
ll t1,k1,t2,k2,f1,f2;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	t1=(c1[0]-'0')*10+c1[1]-'0';
	t2=(c2[0]-'0')*10+c2[1]-'0';
	k1=(s1[0]-'0')*10+s1[1]-'0';
	k2=(s2[0]-'0')*10+s2[1]-'0';
	f1=s1[2]-'A'+1; f2=s2[2]-'A'+1;
	if(f1==6) f1=5;
	if(f2==6) f2=5;
	if(t1==t2)
		cout<<'1'; 
		else {cout<<"0000"<<endl; return 0;}
	if(k1==k2)
		cout<<'1'; else {cout<<"000"<<endl; return 0;}
	if((f1>=1&&f1<=3&&f2>=1&&f2<=3)||(f1<=5&&f1>=4&&f2>=4&&f2<=5))
		cout<<'1'; else {cout<<"00"<<endl; return 0;}
	if(abs(f1-f2)==1) cout<<'1'; else cout<<'0';
	return 0;
}
