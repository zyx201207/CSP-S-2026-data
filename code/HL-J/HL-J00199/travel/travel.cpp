#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int a[200][200];
int main()
{
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
	a['B']['A']=a['A']['B']=1;
	a['C']['B']=a['B']['C']=1;
	a['F']['D']=a['D']['F']=1;
	a['A']['C']=a['C']['A']=2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2)
	{
		cout<<"0000";
		return 0;
	}
	if(s1[0]!=s2[0]||s1[1]!=s2[1])
	{
		cout<<"1000";
		return 0;
	}
	if(a[s1[2]][s2[2]]==0)
	{
		cout<<"1100";
		return 0;
	}
	if(a[s1[2]][s2[2]]!=1)
	{
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
	return 0;
}
