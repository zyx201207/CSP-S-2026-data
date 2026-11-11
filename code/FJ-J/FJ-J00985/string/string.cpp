#include<bits/stdc++.h>
using namespace std;
struct node{
	int num;
	char c;
};
node a[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	int l=0,cnt=0;
	string s="";
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].num>>a[i].c;
		l+=a[i].num;
	}
	for(int i=1;i<=n/2;i++)
	{
		if(a[i].c!=a[n+1-i].c)
		{
			l-=2*(min(a[i].num,a[n+1-i].num));
			cnt+=min(a[i].num,a[n+1-i].num);
			if(a[i].num>=a[n+1-i].num)
			{
				a[i].num-=a[n+1-i].num;
				a[n+1-i].num=0;
			}
			else{
				a[n+1-i].num-=a[i].num;
				a[i].num=0;
			}
		}
	}
	for(int i=1;i<=l;i++)
	{
		for(int j=1;j<=a[i].num;j++)
		{
			s+=a[i].c;
		}
	}
	for(int i=0;i<s.size()/2;i++)
	{
		if(s[i]!=s[l-1-i]) cnt++;
	}
	cout<<cnt;
	return 0;
}

