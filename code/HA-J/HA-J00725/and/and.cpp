#include<bits/stdc++.h>
using namespace std;
struct c
{
	int num=0,x;
}cnt[10005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m,a[10005],s[10005];
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>s[i];
		a[i]=s[i];
		cnt[i].x=i;
		while(s[i]>0)
		{
			if(s[i]%2==1)
			{
				cnt[i].num++;
				
			}
			s[i]/=2;
		}
		cout<<cnt[i].num;
	}
	cout<<a;
	return 0;
}
