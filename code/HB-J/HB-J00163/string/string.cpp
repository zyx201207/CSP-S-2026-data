#include <bits/stdc++.h>
using namespace std;
const int N=200005;
long long n;
struct stu
{
	long long a;
	string c;
}num[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	long long len=0;
	for(long long i=1;i<=n;i++)
	{
		cin>>num[i].a>>num[i].c;
		len+=num[i].a;
	}
	long long l=1,r=n;
	long long now=0;
	long long cnt=0;
	long long last=len/2;
	//cout<<last;
	while(now<=last && l<r)
	{
		if(num[l].c!=num[r].c)
		{
			long long cishu=min(num[l].a,num[r].a);
			cnt+=cishu;
			num[l].a-=cishu;
			num[r].a-=cishu;
			now+=cishu;
		}
		else
		{
			long long cishu=min(num[l].a,num[r].a);
			num[l].a-=cishu;
			num[r].a-=cishu;
			now+=cishu;
		}	
		if(num[l].a==0)
		{
			l++;
			//cout<<1;
		}
		if(num[r].a==0)
		{
			r--;
			//cout<<2;
		}
		//cout<<1;
	}
	cout<<cnt;
	return 0;
}
