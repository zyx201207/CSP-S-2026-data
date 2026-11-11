#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long n;
	cin>>n;
	long long p[n+10]={0};
	char k[n+10];
	for(int i=0;i<n;i++)
		cin>>p[i]>>k[i];
	long long ans=0;
	long long sy=0;
	string s="left";
	for(int i=0;i<n/2;i++)
	{
		if(k[i]!=k[n-i-1]&&s=="left")
		{
			if(sy>=p[n-i-1])
			{
				ans+=p[n-i-1];
				sy-=p[n-i-1];
				s="left";
			}
			if(p[i]+sy>=p[n-i-1])
			{
				ans+=p[n-i-1];
				sy=p[i]-p[n-i-1];
				s="left";
			}
			else
			{
				ans+=p[i]+sy;
				sy=p[n-i-1]-p[i];
				s="right";
			}
		}
		else if(k[i]!=k[n-i-1]&&s=="right")
		{
			if(sy>=p[i])
			{
				ans+=p[i];
				sy-=p[i];
				s="right";
			}
			if(p[n-i-1]+sy>=p[i])
			{
				ans+=p[i];
				sy=p[n-i-1]-p[i];
				s="right";
			}
			else
			{
				ans+=p[n-i-1]+sy;
				sy=p[i]-p[n-i-1];
				s="left";
			}
		}
	}
	if(n%2==1){
		if(sy>=p[n/2+1])
			ans+=p[n/2+1];
		else ans+=sy;
	}
	cout<<ans<<endl;
	return 0;
} 
