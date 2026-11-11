#include<bits/stdc++.h>
using namespace std;
bool tpai(string s1,string s2)
{
	if(s1[0]==s2[0]&&s1[1]==s2[1])
	{
		return true;
	}
	return false;
}
bool tce(int a,int b)
{
	if((a==67&&b==68)||(a == 68&&b==67))
		{
			return false;
		}
	if(a>=65&&a<=67&&b>=65&&b<=67)
	{
		
		return true;
	}
	if(a>=68&&a<=69&&b>=68&&b<=69)
	{
		return true;
	 } 
	return false;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int tc=0,tpa=0,tcc=0;
	int a = int(s1[2]);
	int b = int(s2[2]);	
	if(c1==c2){
		cout<<'1';
		tc =1;
		if(tpai(s1,s2)){
			cout<<'1';
			tpa =1;
			if(tce(a,b)){
				cout<<1;
				tcc = 1;
			}
			else{
				cout<<0;
			}
			if(tc==1&&tpa==1&&tcc==1&&abs(a-b)==1){
				cout<<1;
			}
			else{
				cout<<0;
			} 
		}
		else
		{
			cout<<"000";
		}
	}
	else
	{
		cout<<"0000";
	}
	return 0;
}
