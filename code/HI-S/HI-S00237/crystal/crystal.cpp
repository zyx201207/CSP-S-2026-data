#include<bits/stdc++.h>
using namespace std;
long long a[500005],ans,z,t;
int main(){
//	freopen(".in","r","stdin");
//	freopen(".out","w","stdout");
	int n,m,maxx;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=2;i<=n;i++)
	{
		ans=1;
		z=m;
		t=i-1;
		while(z>0&&t!=0)
		{
			z-=(a[i]-a[t]);
			t--;
			ans++;
		}
		if(ans>maxx)
		{
			maxx=ans;
		}
	}
	cout<<maxx;
	return 0;
}
