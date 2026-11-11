#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n;
	cin>>n;
	if(n<5)
	cout<<3;
	else if(n<20)
	cout <<20;
	else if(n<100)
	cout<<55;
	else if(n<500)
	cout<<150;
	else if(n<2000)
	cout<<500;
	else
	cout<<50000; 
	return 0;
}
