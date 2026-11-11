#include <bits/stdc++.h>
using namespace std;
long long n,s=0;
struct Node{
	long long a;
	char b;
	long long size;
};
Node an[200001];
void y0(int mid,int r)
{
	long long l=1,ans=0,lip=1,rip=n;
	while(l<=mid&&r>mid)
	{
		if(an[lip].b!=an[rip].b) ans++;
		l++,r--;
		if(l<an[lip].size) lip++;
		if(r>an[rip].size) rip--;
	}
	cout<<ans;
	return;
}
void y1(int mid,int r)
{
	long long l=1,ans=0,lip=1,rip=n;
	while(l<mid&&r>mid)
	{
		if(an[lip].b!=an[rip].b) ans++;
		l++,r--;
		if(l<an[lip].size) lip++;
		if(r>an[rip].size) rip--;
	}
	cout<<ans;
	return;
}
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) 
	{
		cin>>an[i].a>>an[i].b;
		s+=an[i].a;
		an[i].size=s;
	}
	if(s%2==1) y1(s/2+1,s);
	else{ y0(s/2,s); }
	return 0;
}

