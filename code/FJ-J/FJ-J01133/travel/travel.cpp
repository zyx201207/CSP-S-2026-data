#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);//请确认文件名（尤其是输出）
	//不要开头就写xxx3.out，有可能覆盖文件
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)return cout<<"0000",0;
	if(s1[0]!=s2[0] or s1[1]!=s2[1])return cout<<"1000",0;
	if(s1[2]<='C' and s2[2]>='D')return cout<<"1100",0;
	if(s1[2]=='B' or s2[2]=='B' or s1[2]=='D' or s2[2]=='D')return cout<<"1111",0;
	cout<<"1110";
	return 0;
}

//I AK IOI
//I AK IOI
//I AK IOI
//I AK IOI

