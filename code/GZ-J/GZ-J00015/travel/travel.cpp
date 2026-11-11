//GZ-J00015 贵阳市第二实验中学 严杨帅森 
#include<iostream>
#include<cstdio>
#include<string>
#define ll long long
ll c1,c2;
std::string s1,s2;
char h[5]={'A','B','C','D','F'};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cin>>c1>>s1>>c2>>s2;
	if(c1 != c2)
	{
		std::cout<<"0000";
		return 0;
	}
	if(s1[0]!=s2[0] || s1[1]!=s2[1])
	{
		std::cout<<"1000";
		return 0;
	}
	ll num1,num2;
	for(ll i=0;i < 5;++i)
	{
		if(s1[2] == h[i])
		{
			num1 = i;
		}
		if(s2[2] == h[i])
		{
			num2 = i;
		}
	}
	if((num1<=2&&num2>=3) || num2<=2&&num1>=3)
	{
		std::cout<<"1100";
		return 0;
	}
	if((num2!=num1+1) && (num2!=num1-1))
	{
		std::cout<<"1110";
		return 0;
	}
	std::cout<<"1111";
	return 0;
}
