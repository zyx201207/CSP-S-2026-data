#include<bits/stdc++.h>
using namespace std;
int a[200010];
char b[200010];
char ch[200000010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i]>>b[i];
	long long ans=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<a[i];j++)
		{
			ch[ans]=b[i];
			ans++;
		}
	long long cnt=0;
	for(int l=0,r=ans;l<=r;l++,r--)
	{
		if(ch[l]!=ch[r])
			cnt++;
	}
	cout<<cnt;
	return 0;
}
