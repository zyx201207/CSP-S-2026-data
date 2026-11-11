//GZ-J00286  谢雨辰  遵义市新蒲中学 
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b;
	char d[10005]={};
	char k[10005]={};
	cin>>a;
	for(int i=0;i<3;i++)
	{
		cin>>d[i];
	}
	cin>>b;	
	for(int i=0;i<3;i++)
	{
		cin>>k[i];
	} 
	if(a==b)
	{
		cout<<"1";	
		if(d[0]==k[0]&&d[1]==k[1])
		{
			cout<<"1";
			if(d[2]=='F'&&k[2]=='D'||k[2]=='F'&&d[2]=='D')
			{
				cout<<"11";
				return 0;
			}else if(d[2]!='F'&&k[2]!='D'&&k[2]!='F'&&d[2]!='D')
			{
				cout<<"1";
				if(abs(d[2]-k[2])==1)
				{
					cout<<"1";
				}else{
					cout<<"0";
				}
			}else
			{
				cout<<"00";
			}
		}else
		{
		cout<<"000";
		}
	}else
	{
		cout<<"0000";
	}	
	return 0;
}

