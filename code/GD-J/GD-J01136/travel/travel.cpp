#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
long long a1,a2,b1,b2,a3,b3;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<c1.size();i++)
	{
		a1=a1*10+c1[i]-'0';
	}
	for(int i=0;i<c2.size();i++)
	{
		b1=b1*10+c2[i]-'0';
	}
	for(int i=0;i<=s1.size()-2;i++)
	{
		a2=a2*10+s1[i]-'0';
	}
	a3=s1[s1.size()-1]-'A'+1;
	for(int i=0;i<=s2.size()-2;i++)
	{
		b2=b2*10+s2[i]-'0';
	}
	b3=s2[s2.size()-1]-'A'+1;
	if(a1==b1)cout<<1;
	else cout<<0;
	if(a1==b1&&a2==b2)cout<<1;
	else cout<<0;
	if(a1==b1&&a2==b2&&((a3<=3&&b3<=3)||(a3>3&&b3>3)))cout<<1;
	else cout<<0;
	if(a1==b1&&a2==b2&&((a3<=3&&b3<=3)||(a3>3&&b3>3))&&abs(b3-a3)==1)cout<<1;
	else cout<<0;
	return 0;
} 
