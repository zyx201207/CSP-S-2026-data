#include<bits/stdc++.h> 
using namespace std;
string a1,a2,b1,b2;
int main()
{
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	string c1,c2;
	c1+=a2[0];
	c1+=a2[1];
	c2+=b2[0];
	c2+=b2[1];
	char s1,s2;
	s1=a2[2];
	s2=b2[2];
	char s3=s1;
	s1=max(s1,s2);
	s2=min(s2,s3);
	int t=0;
	if(int(s1)-3-'A'+1>0&&int(21)-3-'A'+1>0)
		t=1;
	else if(int(s1)-3-'A'+1<=0&&int(21)-3-'A'+1<=0)
		t=1;
	int p=int(s1)-int(s2);
//	cout<<p<<endl;
//	cout<<c1<<" "<<c2<<endl;
	if(a1!=b1)
	{
		cout<<"0000";return 0;
	}
	else if(c1!=c2)
	{
		cout<<"1000";return 0;
	}
	else if(t!=1)
	{
		cout<<"1100";return 0;
	}
	else if(p!=1)
	{
		cout<<"1110";return 0;
	}
	else
		cout<<"1111";return 0;
	return 0;
}
