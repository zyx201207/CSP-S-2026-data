#include<bits/stdc++.h>
using namespace std;
#define ll long long
string s1,str1,s2,str2;
int bo1=0,bo2=0,bo3=0,bo4=0;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    cin>>s1>>str1>>s2>>str2;
    string a1=""+str1[0]+str1[1],a2=""+str2[0]+str2[1];
    char b1=str1[2],b2=str2[2];
    if(s1==s2) bo1=1;
    if(bo1&&a1==a2) bo2=1;
    if(bo2&&(b1<='C'&&b2<='C'||b1>='D'&&b2>='D')) bo3=1;
    if(bo3&&(b1-b2==1||b1-b2==-1||b1>='D'&&b2>='D')) bo4=1;
    cout<<bo1<<bo2<<bo3<<bo4;
	return 0;
}
