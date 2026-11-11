#include <bits/stdc++.h>
using namespace std;
long long n,a[500005],ch[500005],sum[500005];
long long m,ans;
bool cmp(int x,int y)
{
	return x<=y;
}
int main()
{
	//freopen("crystal.in","r",stdin);
	//freopen("crystal.out","w",stdout); 
	cin >>n>>m;
	for(int i = 1;i <= n;i++)
		cin >>a[i];
	sort(a+1,a+n+1,cmp);
	for(int i = 1;i < n;i++)
	{
		ch[i] = a[i+1] - a[i];
		sum[i] = ch[i]+sum[i-1];
	}
	for(int i = 0;i < n;i++)
		for(int j = i;j < n;j++)
			if(sum[j]-sum[i]==m)
			{
				ans=(j-i+1);
				break;
			}
	cout <<ans<<endl;
	return 0; 
}
