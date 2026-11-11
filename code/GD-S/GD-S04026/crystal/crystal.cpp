#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,a[500005];
	int s[500005],ant,max=0;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i]=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			s[j]+=1;
		}
		for(int x=1;x<n;x++)
		{
			ant=0;
			for(int y=i;y<=n;y++)
			{
				if(s[x]==s[y]) ant++;
			}
			if(max<ant) max=ant;
		}
	}
	cout<<max;
	
	return 0;
} 
