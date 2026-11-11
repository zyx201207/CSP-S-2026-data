#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int b[m]={0};
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
	}
	string s;
	int js;
	int ws;
	for(int k=0;k<n;k++)
	{
		s="000000000000000000000000";
		js=0;
		for(int i=k;i<n;i++)
		{
			
			for(int j=0;j<js;j++)
			{
				if(s[j]-48==a[i])
				{
					for(int h=j;h<=i;h++)
					s[h]='0';
					js=0;
					break;
				}
			}
			s[js++]=a[i]+48;
		}
		for(int j=0;j<js;j++)
			{
				ws=s[j]-48-1;
				if(ws>=0)
				b[ws]++;
			}
	}
	for(int i=0;i<m;i++)
	{
		cout<<b[i];
		if(i!=m-1)
		cout<<" ";
	}
	return 0;
}
