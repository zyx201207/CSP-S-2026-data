#include<bits/stdc++.h>;
using namespace std;
int main()
{  
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s;
	int n,x;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		if(s%10==x)
		cout<<"1";
		else cout<<"0";
		if(s%10==x&&s%10==x%10+1&&s%10==x%10-1) 
		cout<<"1";
		else cout<<"0";
		if(s==x+1||s==x-1)
		cout<<"1";
		else cout<<"0";

	return 0;
}
