//GZ-J00320  Îâº«·É 
#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    char c1,s1[3],c2,s2[3];
    cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<'1';
	}
	else
	{
		cout<<'0';
		cout<<'0';
		cout<<'0';
		cout<<'0';
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1])
	{
		cout<<'1';
	}
	else
	{
		cout<<'0';
		cout<<'0';
		cout<<'0';
		return 0;
	}
	if(s1[3]==s2[3])
	{
		cout<<'1';
	}
	else
	{
		cout<<'0';
		cout<<'0';
		return 0;
	}
	if(s1[0]+s1[1]-1==s2[0]+s2[1]||s1[0]+s1[1]+1==s2[0]+s2[1])
	{
		cout<<'1';
	}
	else
	{
		cout<<'0';
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
}

