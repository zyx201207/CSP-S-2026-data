#include<bits/stdc++.h>
using namespace std;

struct turtle{
	int a;
	char c;
};

turtle x[300000];

int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	int n;
	cin>>n;
	long long z=0;
	for(int i=1;i<=n;i++)
	{
		cin>>x[i].a>>x[i].c;
	}
	long long ans=0; 
	int l=1,r=n;
	while(l<r)
	{
		long long mn=min(x[l].a,x[r].a);
		if(x[l].c!=x[r].c)
		{
			ans+=mn;
		}
		x[l].a-=mn;
		x[r].a-=mn;
		if(x[l].a>x[r].a)
		{
			r--;
		}
		else if(x[l].a<x[r].a)
		{
			l++;
		}
		else
		{
			r--;
			l++;
		}
		
	}
	printf("%lld",ans);
	return 0;
}
