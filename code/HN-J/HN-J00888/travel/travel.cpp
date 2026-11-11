#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	bool a=1,b=1,c=1;
	for(int i=0;i<2;i++)
	{
		if(c1[i]==c2[i]){
			a=1;
		}
		else{
			a=0;
		}
	}
	if(a==0)
	{
		cout<<"0000"<<endl;
	}
	else{
		for(int i=0;i<2;i++)
		{
			if(s1[i]==s2[i])
			{
				b=1;
			}
			else{
				b=0;
			}
		}
		if(b=0){
			cout<<"1000"<<endl;
		}
		else{
			if(s1[2]=='D'&&s2[2]!='F')
			{
				cout<<"1100"<<endl;
			}
			else if(s2[2]=='D'&&s1[2]!='F')
			{
				cout<<"1100"<<endl;
			}
			else{
				if(s1[2]=='A'&&s2[2]=='C'){
				    cout<<"1110"<<endl;
				}
				else if(s1[2]=='C'&&s2[2]=='A')
				{
					cout<<"1110"<<endl;
				}
				else{
					cout<<"1111"<<endl;
				}
			}
		}
	}
	return 0;
	
}
