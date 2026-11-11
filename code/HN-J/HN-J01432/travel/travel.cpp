#include<bits/stdc++.h>
using namespace std;
#define int long long
char c1[5],s1[5],c2[5],s2[5];
int jud[6]={1,1,1,0,2,2};
int translate_c(char a[])
{
	int ans=(a[0]-'0')*10+(a[1]-'0');
	return ans;
}
struct Site{
	int sign;
	int mark;
}; 
Site translate_s(char a[])
{
	int ans=(a[0]-'0')*10+(a[1]-'0');	
	if(a[2]=='A')return {ans,0};
	if(a[2]=='B')return {ans,1};
	if(a[2]=='C')return {ans,2};
	if(a[2]=='D')return {ans,4};
	if(a[2]=='F')return {ans,5};
}  
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int carriage1=translate_c(c1),carriage2=translate_c(c2);
	Site site1=translate_s(s1),site2=translate_s(s2);
	if(carriage1==carriage2)
	{
		if(site1.sign==site2.sign)
		{
			if(jud[site1.mark]==jud[site2.mark])
			{
				if(abs(site1.mark-site2.mark)==1)
				{
					cout<<"1111"<<endl;
				}
				else cout<<"1110"<<endl;
			}
			else cout<<"1100"<<endl;
		}
		else cout<<"1000"<<endl;
	}
	else cout<<"0000"<<endl;
	return 0;
}
