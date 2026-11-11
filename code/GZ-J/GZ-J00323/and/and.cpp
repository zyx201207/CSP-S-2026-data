//GZ-J00323 遵义航天实验中学 杨熙晨 
#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200005],ans=0;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a,a+n);
	ans=a[n];
	for(int i=n-1;i>n-m;i--)
	{
		ans&=a[i];
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
