#include<iostream>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	char a,b;
	int c1,c2;
	cin>>c1>>a>>c2>>b;
	if(c1!=c2)
	{
		cout<<"0000"<<endl;
		return 0;
	} 
	if(c1==c2&&a-'A'/10!=b-'A'/10)
	{
	 	cout<<"1000"<<endl;
	 	return 0;
	}
	return 0;
}
