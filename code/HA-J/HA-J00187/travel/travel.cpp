#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int sn1,sn2;
int main() 
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<=1;i++)
	{
		sn1=(s1[i]-'0')+sn1*10;
		sn2=(s2[i]-'0')+sn2*10;
	}
	if(c1==c2)
	{
		cout<<'1';
		if(sn1==sn2)
		{
			cout<<'1';
			if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')
			{
				cout<<'1';
				if(s1[2]+1==s2[2]||s2[2]+1==s1[2])
				{
					cout<<'1';
				} 	 
			}else if(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F'){
				cout<<'1';
				if(s1[2]+2==s2[2]||s2[2]+2==s1[2])
				{
					cout<<'1';
				}
			}
		}
	}else{
		cout<<"0000";
	}
	return 0;
}
