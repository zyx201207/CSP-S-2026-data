#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],maxx,max1,s,z=1;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i],max1=max(max1,a[i]);
	sort(a+1,a+n+1);
	while(max1)
	{
		s++;
		max1/=2;
 	}
 	for(int i=1;i<=s;i++)
 		z*=2;
	if(m==1){
		cout<<a[n];
		return 0;
	}
	if(m==2)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i!=j)continue;
				maxx=min(a[i]^a[j],maxx);
			}
		}
		cout<<z-maxx-4;
		return 0;
	}
	if(m==n)
	{
		for(int i=1;i<=n;i++)
		{
			if(i==1)maxx=a[i];
			if(i>=2)maxx=maxx^a[i];
		}
		cout<<z-maxx-4;
		return 0;
	}
	for(int i=n;i>=n-m+1;i--)
		if(i==1)maxx=a[i];
		else maxx=maxx^a[i];
	cout<<z-maxx-2; 
	return 0;
}

