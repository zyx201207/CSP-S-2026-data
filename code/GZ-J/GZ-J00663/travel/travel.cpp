//GZ-J00663 北京师范大学贵阳附属中学 杨梓萱
#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main() 
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<2;i++){
		if(c1[i]!=c2[i])
		{
			cout<<"0000";
			return 0;
		}
	}
	cout<<1;
	for(int i=0;i<2;i++){
		if(s1[i]!=s2[i])
		{
			cout<<"000";
			return 0;
		}
	}
	cout<<1;
	if((s1[2]>='A' && s1[2]<='C') && (s2[2]>='A' && s2[2]<='C'))
		cout<<1;
	else if((s1[2]=='D' || s1[2]=='F') && (s2[2]=='D' || s2[2]=='F'))
		cout<<1;
	else
	{
		cout<<"00";
		return 0;
	}
	if(int(s1[2])+1==int(s2[2]) || int(s1[2])-1==int(s2[2]))
		cout<<1;
	else
		cout<<0;
	return 0;
}
