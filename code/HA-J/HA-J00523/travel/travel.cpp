#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,l;
long long len1,len2;
bool f[3]={0};
char c[6];
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<s1.size();i++)
	{
		if(s1[i]>='0'&&s1[i]<='9')len1+=s1[i]-'0';
		if(s1[i]>='A'&&s1[i]<='C')f[1]=1;
		else f[1]=0;
		if(isupper(s1[i]))c[1]=s1[i];
	}
	for(int i=0;i<s2.size();i++)
	{
		if(s2[i]>='0'&&s2[i]<='9')len2+=s2[i]-'0';
		if(s2[i]>='A'&&s2[i]<='C')f[2]=1;
		else f[2]=0;
		if(isupper(s2[i]))c[2]=s2[i];
	}
	if(c1==c2)l+='1';
	else l+='0';
	if(c1==c2&&len1==len2)l+='1';
	else l+='0';
	if(c1==c2&&len1==len2&&f[1]==f[2])l+='1';
	else l+='0';
	if(abs(c[2]-c[1])==1&&f[1]==f[2]&&len1==len2&&c1==c2)l+='1';
	else l+='0';
	cout<<l;
	return 0;
}
