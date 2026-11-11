#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int ans=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)
	{
		cout<<"0000";
		return 0;
	}
	else ans+=1000;
	if(s1[0]==s2[0]&&s1[1]==s2[1])
	{
		ans+=100;
	}
	else
	{
		cout<<"1000";
		return 0;
	}
	if(s1[2]>='D'&&s2[2]>='D'||s1[2]<='C'&&s2[2]<='C')
	{
		ans+=10;
	}
	else
	{
		cout<<"1100";
		return 0;
	}
	if(s1[2]+1==s2[2]||s1[2]-1==s2[2])
	{
		ans++;
	}
	cout<<ans;
	return 0;
}

