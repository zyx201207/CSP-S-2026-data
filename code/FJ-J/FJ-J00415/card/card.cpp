#include <bits/stdc++.h>
using namespace std;
bool num_now[300005];
int num[300005];
int a[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int b;
		cin>>b;
		a[i] = b;
		num_now[b] = !num_now[b];
		
	}
	int j=1;
	for(int j=1;j<=n-1;j++)
	{
	    for(int i=j;i<=n;i++) num[i]+=num_now[i];
	    num_now[j] = !num_now[j];
    }
    for(int i=1;i<=m;i++) cout<<num[i]<<" ";
	return 0;
}
