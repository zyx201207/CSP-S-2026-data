#include<bits/stdc++.h>
using namespace std;
int n;
long long len,cnt;
struct node{
	int num;
	string s;
}a[200005];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i].num>>a[i].s;
		len+=a[i].num;
	}
	long long l=1,r=len;
	while(l<=r)
	{
		int suml=0,idl=1,sumr=0,idr=1;
		while(suml+a[idl].num<l) suml+=a[idl].num,idl++;
		while(sumr+a[idr].num<r) sumr+=a[idr].num,idr++;
		if(a[idl].s!=a[idr].s) cnt++;
		l++,r--;
	}
	cout<<cnt;
	return 0;
}
