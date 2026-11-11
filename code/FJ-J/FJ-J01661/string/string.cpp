#include <bits/stdc++.h>
using namespace std;
const int N=1e8+5;
long long n,m;
long long cnt=0,ans=0;
//cnt计算改变次数 
//ans计算a数组里面有几个字母 
char b;
char a[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>m;
		cin>>b;
		for(int j=ans;j<ans+m;j++)
		{
			a[j]=b;
		}
		ans=ans+m;
	}
	for(int i=0;i<ans/2;i++)
	{
		if(a[i]!=a[ans-i-1])
		{
			cnt++;
		}
	}
	cout<<cnt;
	
	return 0;
}
