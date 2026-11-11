#include<bits/stdc++.h>
using namespace std;
int n,cnt;
int a[100005];
char c[100005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i]>>c[i];
	}
	int i=1,j=n,mid=n/2;
	while(i<=mid && j>=mid)
	{
		int shu=min(a[i],a[j]);
		if(c[i]!=c[j])
		{
			cnt+=shu;	
		}
		a[i]-=shu;
		a[j]-=shu;
		if(a[i]==0) i++;
		if(a[j]==0) j--;
	}
	cout<<cnt;
	return 0;
}
