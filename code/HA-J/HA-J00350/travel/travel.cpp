#include <bits/stdc++.h> 
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string c1,s1,c2,s2,ans;
	cin>>c1>>s1>>c2>>s2;
	string n1;
	n1=s1[0]+s1[1];
	string n2;
	n2=s2[0]+s2[1];
	if(c1==c2)
	{
		cout<<"1";
		if(n1==n2)
		{
			cout<<"1";
			if(s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')
			{
					cout<<"1";
				    if(s1[2]-s2[2]==1||s2[2]-s1[2]==1)
					    cout<<"1"<<endl;
					else 
					    cout<<"0"; 
			}
			else if(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F')
			{
					cout<<"11"<<endl;
			}
			else 
			{
				cout<<"00"<<endl;
			}
		}
        else
		{
			cout<<"000"<<endl;
		}
	}
	else 
	{
		cout<<"0000"<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
