// 贵阳市第三十四中学,廖泓博,GZ-S00269 
#include <bits/stdc++.h>
using namespace std;
int n,m,a[10000],s=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		s+=a[n/2]-a[i];
	}
	if(s==a[n/2]&&s<=m)
	{
		cout<<n/2+1;
	}
}
