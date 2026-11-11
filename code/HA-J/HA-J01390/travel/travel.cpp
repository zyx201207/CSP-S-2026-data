#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string c1,s1,c2,s2,a[4],ans;
	cin>>c1>>s1>>c2>>s2;
	
	if(c1==c2)
		a[0] = "1";
	else
		a[0] = "0";
	
	if(s1[0]==s2[0] && s1[1]==s2[1])
		a[1] = "1";
	else
		a[1] = "0";
	
	if((s1[0]==s2[0] && s1[1]==s2[1])&&(s1[2]==s2[2]+1||s1[2]==s2[2]-1 || s1[2]==s2[2]+2||s1[2]==s2[2]-2 || s1[2]==s2[2]+3||s1[2]==s2[2]-3))
		a[2] = "1";
	else
		a[2] = "0";
	
	if((s1[0]==s2[0] && s1[1]==s2[1])&&(s1[2]==s2[2]+1 || s1[2]==s2[2]-1))
		a[3] = "1";
	else
		a[3] = "0";
	
	for(int i=0;i<4;i++)
		ans += a[i];
	cout<<ans;
	
	return 0;
}

