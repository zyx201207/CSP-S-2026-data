//GZ-J00543 贵阳市第十八中学 王相宇  
#include<bits/stdc++.h>
using namespace std;
int n,m,a[1000010],b[1000010];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		b[a[i]]=i;
	}
	for(int i=1;i<=n;i++)
	{
		cout<<b[a[i]]<<' ';
	}
	return 0;
}
    
