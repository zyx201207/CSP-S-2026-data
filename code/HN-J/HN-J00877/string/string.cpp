#include<bits/stdc++.h>
using namespace std;
int n;
long long sum=0;
struct str
{
	int num;
	char c;
}a[200050];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n; 
	for(int i=1;i<=n;i++)
		cin>>a[i].num>>a[i].c;
	int l=1,r=n;
	while(l<r)
	{
		int minn=min(a[l].num,a[r].num);
		sum+=minn*(a[l].c!=a[r].c);
		a[l].num-=minn;
		a[r].num-=minn;
		if(a[l].num==0) l++;
		if(a[r].num==0) r--;
	}
	cout<<sum;
	return 0;
}
