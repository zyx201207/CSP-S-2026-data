#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct node{
	int num;
	char s;
};
node a[N];
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long sum=0;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i].num>>a[i].s;
	for(int i=1;i<=n/2;i++)
	{
		if(a[i].s!=a[n].s)
			sum+=max(a[i].num,a[n].num);
	}
	cout<<sum;
	return 0;
}
