#include<bits/stdc++.h>
using namespace std;
long long n,m;
const int N=5*1e5;
long long a[N],f[N];
long long sum,ans,maxn=-0x3f3f3f3f;
//void dfs(int pos)
//{
//	if (sum>=m)
//	{
//		if (sum==m) maxn=max(ans,maxn);
//		else maxn=max(ans-1,maxn);
//		return ;
//	}
//	for (int i=1;i<=pos;i++)
//	{
//		sum+=(a[pos]-a[i]);
//		ans++;
//		dfs(pos+1);
//		sum-=(a[pos]-a[i]);
//		ans--;
//	}
//}
int main(){
	freopen("crytal.in","r",stdin);
	freopen("crytal.out","w",stdout);
	cin>>n>>m;
	int cnt=0,cnt2=0;
	for (int i=1;i<=n;i++) 
	{
		cin>>a[i];
		if (a[i]==i) cnt++;
		if (i>=2&&a[i]-a[i-1]==a[i-1]-a[i-2]) cnt2++;
	}
	if (cnt==n) 
	{
		if ((long long)sqrt(2*m)>n) cout<<n<<endl;
		else cout<<(long long)sqrt(2*m)<<endl;
		return 0;
	}
	else if (cnt2==n-2)
	{
		if ((long long)(m/(a[2]-a[1])>n)) cout<<n<<endl;
		else cout<<(long long)(m/(a[2]-a[1]))<<endl;
		return 0;
	}
	sort(a+1,a+1+n);
	for (int i=1;i<=n;i++) f[i]=abs(a[i]-a[i-1]);
	for (int i=1;i<=n;i++)
	{
		f[i]=f[i-1]+f[i];
		if (f[i]<=m) ans++;
	}
	cout<<ans<<endl;
	return 0;
}
