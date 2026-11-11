#include<bits/stdc++.h>
#include<string>

using namespace std;

string s1,c1,s2,c2;
string tmp1,tmp2;
string ans="";
string ce[10]={"AB","BA","AC","CA","BC","CB","DF","FD"};
string ss[10]={"AB","BA","BC","CB","DF","FD"};

//两张车票对应的座位是否在同一节车厢；
//两张车票对应的座位是否在同一节车厢的同一排；
//两张车票对应的座位是否在同一节车厢的同一排，且位于过道的同一侧；
//两张车票对应的座位是否相邻。

bool check(string x,string y)
{
	string tmp=x+y;
	for(int i=0;i<8;i++)
	{
		if(tmp==ce[i])	return true;
	}
	return false;
}

bool check1(string x,string y)
{
	string tmp=x+y;
	for(int i=0;i<6;i++)
	{
		if(tmp==ss[i])	return true;
	}
	return false;
}

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	//freopen("travel5.in","r",stdin);
	//freopen("travel5.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		ans+='1';
		tmp1=s1.substr(0,2),tmp2=s2.substr(0,2);
		if(tmp1==tmp2)
		{
			ans+='1';
			tmp1=s1.substr(2,1),tmp2=s2.substr(2,1);
			if(check(tmp1,tmp2))
			{
				ans+='1';
				if(check1(tmp1,tmp2))
				{
					ans+='1';
				}
				else ans+='0';
			}
			else
			{
				ans+="00";
			}
		}
		else ans+="000";
	}
	else ans+="0000";
	cout<<ans<<endl;
	
	return 0;
} 
