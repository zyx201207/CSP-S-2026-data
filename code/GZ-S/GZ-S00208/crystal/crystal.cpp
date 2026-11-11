//GZ-S00208 六枝特区第九中学 陈洪鑫 
#include<bits/stdc++.h>
using namespace std;
long long n,m,a,b;
int main()
{   
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	cin>>n>>m>>a>>b;
	int a=n;
	long long c[100000]
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		c[i]=c[i-1]+c[i];
	}
	cout<<a*c*n;
	return 0;
}
