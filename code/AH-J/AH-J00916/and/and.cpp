#include<bits/stdc++.h>
using namespace std;
long long a[100010];
long long b[100010];
int cnt=0;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		b[i]=a[i]&a[i+1];
		cnt=max(b[i],b[i-1]);
	}
	cout<<cnt<<endl;
	return 0;
}
//Eim si equ ter thi Csp-J tos life tis.
//ene had~col eim geiteiyey 104?
