#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int a[N],b[N],t[N],s[N];

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,l = 0;
	cin>>n>>m;
	for(int i = 1 ; i <= n ; i++)cin>>a[i];
	for(int i = 1 ; i <= n ; i++)
	{
		l = 0;
		memset(t,0,sizeof(t));
		for(int j = i ; j <= n ; j++)
		{
			if(t[a[j]])l = t[a[j]] - 1;
			s[++l] = a[j],t[a[j]] = l;
		}
		for(int j = 1 ; j <= l ; j++)b[s[j]]++;
	}
	for(int i = 1 ; i <= m ; i++)cout<<b[i]<<" ";
	return 0;
}
