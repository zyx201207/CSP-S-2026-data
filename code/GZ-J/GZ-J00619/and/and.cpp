//GZ-J00619 北京师范大学贵阳附属中学 杨然
#include <bits/stdc++.h>
using namespace std;
const int maxn = 2e5;
long long n,m,a[maxn];
bool cmp(long long a,long long b){
	if(a>b)return true;
	else return false;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+1+n,cmp);
    int ans;
	while(ans < a[m+1])
	{
		ans = (a[m] & a[m-1]);
		m++;
	}
	cout<<ans;
	return 0;
}
