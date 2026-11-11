//GZ-J00718 兴义市弘毅中学 李勇霖
#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int m,n;
int main()
{
	freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	m=s1[2]-'A'+1;
	n=s2[2]-'A'+1;
	if(c1!=c2)
	{
		cout<<"0000";
		return 0;
	}
	if(s1[0]!=s2[0]||s1[1]!=s2[1])
	{
		cout<<"1000";
		return 0;
	}
	if(m>3&&n<=3)
	{
		cout<<"1100";
		return 0;
	}
	if(n>3&&m<=3)
	{
		cout<<"1100";
		return 0;
	}
	if(m-n!=1&&n-m!=1)
	{
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
	 return 0;
}
