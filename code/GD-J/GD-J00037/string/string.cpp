#include<bits/stdc++.h>
using namespace std;

int n;
long long vc[200100],ans;
char po[200100];

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>vc[i]>>po[i];
	}
	int l=1,r=n;
	while(l<r)
	{
		while(vc[l]>=vc[r]&&l<r)
		{
			long long op=vc[l]-vc[r];
			if(po[l]!=po[r])	ans+=vc[r];
			vc[l]=op;
			r--;
		}
		while(vc[r]>vc[l]&&l<r)
		{
			long long op=vc[r]-vc[l];
			if(po[l]!=po[r])	ans+=vc[l];
			vc[r]=op;
			l++;
		}
	}
	cout<<ans;
	return 0;
}
