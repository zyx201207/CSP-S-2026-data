#include<bits/stdc++.h>
using namespace std;

int main()
{
		freopen("travel.in","r",stdin);
		freopen("travel.out","w",stdout);
	
	int a=0;
	string c1,s1,c2,s2;
	int sum=0;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		sum++;
	}
	if(c1!=c2)
	{
		
		cout<<0000;
		return 0;
	}
	//1
	if(s1[0]==s2[0]&&s1[1]==s2[1])
	{
		sum++;
	}
	if(s1[0]!=s2[0]||s1[1]!=s2[1])
	{
		cout<<1000;
		return 0;
	}
	//2
	if(s1[2]==64||s1[2]==65||s1[2]==66&&s2[2]==64||s2[2]==65||s2[2]==66)
	{
		sum++;
	}
	else
	{
		cout<<1100;
		return 0;
	}
	if(s1[2]==67||s1[2]==69&&s2[2]==67||s2[2]==69)
	{
		a=1; 
	}
	//3
	if(a=1)
	{
		cout<<1111;
		return 0;
	}
	if(s1[2]==64&&s2[2]==65)
	{
		cout<<1111;
	}
	if(s1[2]==65&&s2[2]==66)
	{
		cout<<1111;
	}
//		freopen("travel.in","r",stdin);
//		freopen("travel.out","w",stdout);
//		freopen("travel.in","r",stdin);
//		freopen("travel.out","w",stdout);
//		freopen("travel.in","r",stdin);
//		freopen("travel.out","w",stdout);	
//		freopen("travel.in","r",stdin);
//		freopen("travel.out","w",stdout);
//		freopen("travel.in","r",stdin);
//		freopen("travel.out","w",stdout);
//		freopen("travel.in","r",stdin);
//		freopen("travel.out","w",stdout);
	//91919191114514(
	//wo yao hui jia da wumeng!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//wo yao hui jia da wumeng!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//wo yao hui jia da wumeng!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//wo yao hui jia da wumeng!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//wo yao hui jia da wumeng!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//wo yao hui jia da wumeng!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//wo yao hui jia da wumeng!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//wo yao hui jia da wumeng!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//wo yao hui jia da wumeng!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//wo yao hui jia da wumeng!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//wo yao hui jia da wumeng!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//wo yao hui jia da wumeng!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//wo yao hui jia da wumeng!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//wo yao hui jia da wumeng!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//wo yao hui jia da wumeng!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//wo yao hui jia da wumeng!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//wo yao hui jia da wumeng!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//wo yao hui jia da wumeng!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//wo yao hui jia da wumeng!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//wo yao hui jia da wumeng!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//wo yao hui jia da wumeng!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//wo yao hui jia da wumeng!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//wo yao hui jia da wumeng!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//wo yao hui jia da wumeng!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//wo yao hui jia da wumeng!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//wo yao hui jia da wumeng!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//wo yao hui jia da wumeng!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//wo yao hui jia da wumeng!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//wo yao hui jia da wumeng!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//wo yao hui jia da wumeng!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//wo yao hui jia da wumeng!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//wo yao hui jia da wumeng!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//wo yao hui jia da wumeng!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//wo yao hui jia da wumeng!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//wo yao hui jia da wumeng!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//wo yao hui jia da wumeng!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//wo yao hui jia da wumeng!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//wo yao hui jia da wumeng!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//wo yao hui jia da wumeng!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//wo yao hui jia da wumeng!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//wo yao hui jia da wumeng!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//wo yao hui jia da wumeng!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//wo yao hui jia da wumeng!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//wo yao hui jia da wumeng!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//wo yao hui jia da wumeng!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//wo yao hui jia da wumeng!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//wo yao hui jia da wumeng!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//wo yao hui jia da wumeng!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//wo yao hui jia da wumeng!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//wo yao hui jia da wumeng!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//wo yao hui jia da wumeng!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//wo yao hui jia da wumeng!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//wo yao hui jia da wumeng!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//wo yao hui jia da wumeng!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//wo yao hui jia da wumeng!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//wo yao hui jia da wumeng!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//wo yao hui jia da wumeng!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//wo yao hui jia da wumeng!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//wo yao hui jia da wumeng!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//wo yao hui jia da wumeng!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//wo yao hui jia da wumeng!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//wo yao hui jia da wumeng!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//wo yao hui jia da wumeng!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//wo yao hui jia da wumeng!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//wo yao hui jia da wumeng!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//wo yao hui jia da wumeng!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//wo yao hui jia da wumeng!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//wo yao hui jia da wumeng!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//wo yao hui jia da wumeng!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//wo yao hui jia da wumeng!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//wo yao hui jia da wumeng!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//wo yao hui jia da wumeng!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//wo yao hui jia da wumeng!!!!!!!!!!!!!!!!!!!!!!!!!!!
	
	return 0;
}
