#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e5+10;
int n,a[maxn],ans;
char c[maxn];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	for(int i=1,j=n;i<j;){
		if(c[i]!=c[j])ans+=min(a[i],a[j]);
		if(a[i]==a[j])i++,j--;
		else if(a[i]>a[j])a[i]-=a[j],j--;
		else a[j]-=a[i],i++;
	}
	cout<<ans;
	return 0;
}
