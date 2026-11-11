#include <iostream>
#include <string>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);freopen("travel.out","w",stdout);

	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2)
	{
		cout<<"1";
		if(s1.substr(0,2)==s2.substr(0,2))
		{
			cout<<"1";
			if((s1[2]<67.5&&s2[2]<67.5)
			||(s1[2]>67.5&&s2[2]>67.5))
			{
				cout<<"1";
				if(
					((s1[2]<67.5&&s2[2]<67.5)
					&&abs(s2[2]-s1[2])==1)||
					((s1[2]>67.5&&s2[2]>67.5)
					&&abs(s2[2]-s1[2])==2)
				)
				{
					cout<<"1";
				}else{cout<<"0";}
			}else{cout<<"00";}
		}else{cout<<"000";}
	}else{cout<<"0000";}
	cout<<"\n";

	fclose(stdin);fclose(stdout);
	return 0;
}
