#include<bits/stdc++.h>
#define endl'\n'
using namespace std;

int n,m,sum=0,ans=0;
int maxn;
int a[100010],b[100010];
int main()
{
	//freopen("and.in","r","stdin");
	//freopen("and,out","w","stdout");
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		a[i]=a[i]+'A'-10;
		b[i]=a[i]<<a[i];
		
	}
	sort(b+1,b+n+1);
	for(int i=1;i<=n;i++)
	{
		if(b[i]<=b[i])
		{
			sum++;
		}
		maxn=max(b[i],maxn);
	}
	cout<<maxn;
	
	return 0;
}
