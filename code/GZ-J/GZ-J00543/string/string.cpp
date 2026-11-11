//GZ-J00543 贵阳市第十八中学 王相宇  
#include<bits/stdc++.h>
using namespace std;
string s;
unsigned long long n,cnt;
struct a
{
	long long num;
	char t;
}a[200010];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(long long i=1;i<=n;i++)
	{
		long long qwq;
		char qaq;
		cin>>qwq>>qaq;
		a[i].num=qwq,a[i].t=qaq;
	}
	long long l=1,r=n;
	while(l<=r)
	{
		if(a[l].t==a[r].t)cnt++,cnt--;
		else if(a[l].t!=a[r].t)cnt+=max(a[l].num,a[r].num);
		else if(a[l].num!=a[r].num)cnt+=abs(a[l].num-a[r].num);
		l++,r--;
	}
	cout<<cnt;
	return 0;
}
    
