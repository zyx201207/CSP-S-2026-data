#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200005],ans,q[200005],p[200005],i=1,j=1,s1=1,s2;
char c[200005];
signed main(){
	freopen("string.in","r",stdin);freopen("string.out","w",stdout);
	cin>>n,s2=n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i],p[i]=p[i-1]+a[i-1];
	for(int i=n;i>=1;i--)q[i]=q[i+1]+a[i+1];
	for(;s1<s2;){
		if(c[s1]!=c[s2])ans+=min(a[s1]-i,a[s2]-j)+1;
		int x=min(a[s1]-i,a[s2]-j)+1;
		i+=x,j+=x;
		if(i==a[s1]+1)s1++,i=1;if(j==a[s2]+1)s2--,j=1;
	}
	cout<<ans;
	return 0;
}
