#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n=0;
	long long si[200005];
	char sc[200005];
	string l="";
	unsigned long long cnt=0;
	
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	cin>>n;
 	for(int i=1;i<=n;i++)	cin>>si[i]>>sc[i];
 	
	int idx=1;
	
 	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=si[i];j++)
		{
			l[idx]=sc[i];
			idx+=1;
		}
	}
	for(int i=1;i<=ceil((idx-1)/2.0);i++)
	{
		if(l[i] != l[idx-i])	cnt++;
	}
	cout<<cnt;
	return 0;
}
