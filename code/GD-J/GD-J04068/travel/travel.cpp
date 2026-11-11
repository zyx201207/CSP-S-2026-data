#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+5;
string c1,c2,s1,s2;
int a1,a2,a3,a4;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>s1>>s2;
	if(c1==s1)	a1=1;
	if(a1&&c2[0]==s2[0]&&c2[1]==s2[1])	a2=1;
	if(a1&&a2&&((c2[2]<='C'&&s2[2]<='C')||(c2[2]>='D'&&s2[2]>='D')))	a3=1;
	if(a1&&a2&&a3&&((abs(c2[2]-s2[2])==1&&c2[2]!='D'&&s2[2]!='D')||(c2[2]=='D'&&s2[2]=='F')||(c2[2]=='F'&&s2[2]=='D')))	a4=1;
	cout<<a1<<a2<<a3<<a4;
	return 0;
}
