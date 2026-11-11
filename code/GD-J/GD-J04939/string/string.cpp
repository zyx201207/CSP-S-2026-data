#include<bits/stdc++.h>
using namespace std;
long long n,ans;
long long num;
string a = "",b;

int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	//别忘记接触注释！！！！！ 
	cin>>n;
	for(long long i = 1;i<=n;i++)
	{
		cin>>num;
		cin>>b;
		for(long long j = 1;j<=num;j++)//会超时 
		{
			a+=b;
		}
		
	}	
	long long len = a.size();
	long long l = 0,r = len-1;
	while(l<=r)
	{
		if(a[l]!=a[r])
		{
			ans++;
		}
		l++;
		r--;
	}
	cout<<ans;

	return 0;
}


