#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int c1,c2,p1,p2;
	char l1,l2;
	cin>>c1>>p1;
	cin>>l1;
	cin>>c2>>p2;
	cin>>l2;
	
	if(c1==c2)
	cout<<1;
	else
	cout<<0;
	
	if(p1==p2&&c1==c2)
	cout<<1;
	else
	cout<<0;
	
	if(p1==p2&&((l1<'D'&&l2<'D')||(l1>'C'&&l2>'C'))&&c1==c2)
	{
		cout<<1;
	}
	else
	cout<<0;
	
	if(p1==p2&&((l1<'D'&&l2<'D')||(l1>'C'&&l2>'C'))&&abs(l1-l2)==1&&c1==c2)
	{
		cout<<1;
	}
	else
	cout<<0;
	return 0;
} 
