#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;

long long a[N],q[N];
int head=1,tail=0;
int cnt=0;
long long summ=0;

int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	int n,res=0;
	long long m;
	cin>>n>>m;
	for (int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	for (int i=1;i<=n;i++)
	{
		while (head<=tail&&summ+1ll*cnt*(a[i]-a[i-1])>m)
		{
			summ-=(a[q[tail]]-a[q[head]]);
			cnt--;
			head++;
		}
		summ+=1ll*cnt*(a[i]-a[i-1]);
		cnt++;
		q[++tail]=i;
		res=max(res,cnt);
	}
	cout<<res<<endl;

    	return 0;
}