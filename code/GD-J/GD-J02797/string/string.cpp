#include<bits/stdc++.h>
using namespace std;
int n,zf[27];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	int mi=1e9,zfs=0;
	bool ai=1;
	for(int i=1;i<=n;i++)
	{
		int x;
		char c;
		cin>>x>>c;
		if(zf[c-'a'+1]==0) zfs++;
		zf[c-'a'+1]++;		
		mi=min(mi,x);
		if(x!=1) ai=0;
	}
	int ma=-1;
	for(int i=1;i<=26;i++) ma=max(ma,zf[i]);
	if(n==1) cout<<0<<"\n";
	else if(n==2)
	{
		if(zfs==1) cout<<0<<"\n";
		else if(zfs==2) cout<<mi<<"\n";
	}
	else if(ai==1)
	{
		if(ma>1) cout<<n-ma<<"\n";
		else cout<<n-1;	
	} 
	return 0;	
} 
