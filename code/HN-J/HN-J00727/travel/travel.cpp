#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	int s11,s12,s21,s22,s13,s23;
	cin>>c1>>s1>>c2>>s2;
	s11=s1[0],s12=s1[1],s13=s1[2];
	s21=s2[0],s22=s2[1],s23=s2[2];
	if(c1==c2)
	{
		cout<<1;
		if((s11==s21)&&(s12==s22))
		{
			cout<<1;
			if((s13<=67)&&(s13>=65)&&(s23<=67)&&(s23>=65))
			{
				if((s13==66)||(s23==66)) cout<<11<<endl;
				else cout<<10<<endl;
			}
			else if((s13>67)&&s23>(67)) cout<<11<<endl;
			else cout<<"00"<<endl;
		}
		else cout<<"000"<<endl;
	}
	else cout<<"0000"<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
