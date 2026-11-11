#include<bits/stdc++.h>
#define int long long
#define fre freopen("string.in","r",stdin),freopen("string.out","w",stdout)
using namespace std;
const int MAXN=5e5+34;
int n,a[MAXN],ans;
char b[MAXN];
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	fre,cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>b[i];
	for(int i=1,j=n,x=min(a[i],a[j]);i<j;a[i]-=x,a[j]-=x,i+=(a[i]==0),j-=(a[j]==0),x=min(a[i],a[j])) ans+=x*(b[i]!=b[j]);
	cout<<ans;
	return 0;
}
