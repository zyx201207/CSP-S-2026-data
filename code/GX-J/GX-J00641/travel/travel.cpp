#include<bits/stdc++.h>
using namespace std;
char p[10],k[10];
int main()
{
	freeopen("travel.in","r",stdin);
	freeopen("travel.out,"w",stdout);
	char a[5],c[5];
	for(int i=1;i<=2;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=3;i++)
	{
		cin>>p[i];
	}
	for(int i=1;i<=2;i++)
	{
		cin>>c[i];
	}
	for(int i=1;i<=3;i++)
	{
		cin >>k[i];
	}
	
	if(a[1]==c[1] && a[2]==c[2])
		cout<<"1";
	else
		cout<<"0";
	
	if(p[2]= k[2] && p[1]==k[1])
		cout<<"1";
	else
		cout<<"0";
	
	if((p[3]=='A' || p[3]=='B' || p[3]=='C') && (k[3]=='A' || k[3]=='B' || k[3]=='C'))
		cout<<"1";
	else if((p[3]=='D' || p[3]=='F') && (k[3]=='D' || k[3]=='F'))
		cout<<"1";
	else
		cout<<"0";
	
	if(p[3]+1==k[3] || p[3]-1==k[3] || k[3]+1==p[3] || k[3]-1==p[3])
		cout<<"1";
	else
		cout<<"0";
	return 0;
}
