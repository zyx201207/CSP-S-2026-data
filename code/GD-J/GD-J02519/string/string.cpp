#include<bits/stdc++.h>
using namespace std;
long long n;
struct node
{
	char c;
	long long cnt;
};
node a[200005],b[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for(int i = 1;i <= n;i++)
	{
		long long num;
		char ch;
		cin >> num >> ch;
		a[i].c = ch;
		a[i].cnt = num;
		b[n-i+1].c = ch;
		b[n-i+1].cnt = num;
	}
	long long ans = 0;
	int i = 1,j = 1;
	while(i <= n && j <= n)
	{
		if(a[i].c != b[j].c)
			ans+=min(a[i].cnt,b[j].cnt);
		if(a[i].cnt>b[j].cnt)
		{
			a[i].cnt-=b[j].cnt;
			b[j].cnt = 0;
			j++;
		}
		else if(a[i].cnt<b[j].cnt)
		{
			b[j].cnt-=a[i].cnt;
			a[i].cnt = 0;
			i++;
		}
		else
		{
			b[j].cnt = 0;
			a[i].cnt = 0;
			i++;
			j++;
		}
	}
	cout << (ans/2);
	return 0;
}
