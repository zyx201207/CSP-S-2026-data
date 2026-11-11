#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    string c1,c2,s1,s2;
    int a,b,t;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
    cout<<"1"<<endl;
    if(s1[0]==s2[0]&&s1[1]==s2[1])
	{
	cout<<"1"<<endl;
	a=s1[2]-'A'+1;
    b=s2[2]-'A'+1;
    if((a<=3&&b<=3)||(a>3&&b>3))
    {
    cout<<"1"<<endl;
	if(a<b)
	t=b;b=a;a=t; 
    if(a-1==b)
    cout<<"1"<<endl;
    else
    cout<<"0"<<endl;
	}
	else
	{
		cout<<"0"<<endl; 
		cout<<"0"<<endl; 
	}
	}
	else
	{
		cout<<"0"<<endl; 
		cout<<"0"<<endl; 
		cout<<"0"<<endl; 
	}
	}
	else
	{
		cout<<"0"<<endl; 
		cout<<"0"<<endl; 
		cout<<"0"<<endl; 
		cout<<"0"<<endl; 
	}
    return 0;
}
