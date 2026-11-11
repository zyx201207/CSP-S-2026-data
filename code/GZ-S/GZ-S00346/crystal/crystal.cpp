//GZ-S00346 贵州省凯里市第一中学 何奕歆 
#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	long long n,m;
	cin>>n>>m;
	long long r[n+1],s[n+1];
	for(int i=1;i<=n;i++)
		cin>>r[i];
	sort(r+1,r+1+n);
		
	
	int p=0;
	
	for(int i=1;i<n;i++)
		s[i]=abs(r[i+1]-r[i]);
			
	for(int i=1;i<n;i++)
	{
		int step=m,xb=i,sum=0,lp=1;
		while(sum<=m&&xb<n)
		{
			if((sum+xb*s[xb])<=m)
			{
				sum+=xb*s[xb];lp++;xb++;
			}
			else break;
		}
			
		p=max(lp,p);
	}
	cout<<p;	
	
 	return 0;
	
	
}

