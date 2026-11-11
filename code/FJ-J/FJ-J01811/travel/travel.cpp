#include<bits/stdc++.h> 
using namespace std;
string c1,s1,c2,s2;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	bool a[10]={false};
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)
	{
		cout<<"0000";
		return 0;
	}
	else
	{
		cout<<1;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1])
	{
		cout<<1;
	}
	else
	{
		cout<<"000";
		return 0;
	}
	a[s1[2]-'0'-17]=true;
	a[s2[2]-'0'-17]=true;
	int ans=0;
	for(int i=0;i<3;i++)
	{
		if(a[i]==true)
		{
			ans++;
		}
	}
	if(ans==1)
	{
		cout<<"00";
		return 0;
	}
	else if(ans==0)
	{
		cout<<"11";
		return 0;
	}
	else
	{
		cout<<1;
	}
	for(int i=1;i<=2;i++)
	{
		if(a[i]==a[i+1])
		{
			cout<<1;
			return 0;
		}
	}
	cout<<0;
	return 0;
}
