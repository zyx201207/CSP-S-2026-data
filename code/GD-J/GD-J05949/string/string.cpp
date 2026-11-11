#include<bits/stdc++.h>
using namespace std;
const int N=2e5+20;
int n,l,li,r,ri;
struct si
{
	int a;
	char c;
} s[N];
long long ans;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);	
	scanf("%d",&n);
	for(int i=1;i<=n;i++) 
	{
		scanf("%d %c",&s[i].a,&s[i].c);
	} 
	l=1,r=n;
	// 输入
	while(l<r)
	{
		long long ls=s[l].a-li,rs=s[r].a-ri;
		if(s[l].c!=s[r].c)
		{
			if(ls>rs)
			{
				ans+=rs;
				ri=0,r--; // 左移
				li+=rs; //a[l]用ls个修改次数 
			}
			else if(ls<rs)
			{
				ans+=ls;
				li=0,l++; // 右移 
				ri+=ls; //a[r]用ls个修改次数 
			}
			else if(ls==rs)
			{
				ans+=ls;
				li=0,l++; // 右移 
				ri+=ls; //a[r]用ls个修改次数 
			}
		}
		else 
		{
			if(ls<rs)
			{
				l++,li=0;
				ri+=ls;
			}
			else if(ls>rs)
			{
				r--,ri=0;
				li+=rs;
			}
		}
	}
	cout<<ans;
	return 0;
} 
