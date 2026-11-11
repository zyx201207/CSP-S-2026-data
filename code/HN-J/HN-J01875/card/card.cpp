#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int a,b;
	cin>>a>>b;
	
	if(a!=b)
	{
		a += 1;
	}
	else 
	{
		a = 0;
	}
	
	
	
	
	
	
	cout<<a;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
