//GZ-J00351 贵阳市双龙华麟学校 曾凡一 
#include<bits/stdc++.h>
using namespace std;
long long n,pos,ans;
char num[2000005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		long long a;
		char b;
		cin>>a>>b;
		for(int j=pos;j<=pos+a;j++)
		{
			num[j]=b;
		}
		pos+=a; 
	}
	long long l=0,r=pos-1;
	for(long long i=0;i<=pos/2-1;i++)
	{
		if(num[l]==num[r])
		{
			l++;
			r--;
			continue;
		}
		ans++,l++,r--;
	}
	cout<<ans<<endl;
	return 0;
}
