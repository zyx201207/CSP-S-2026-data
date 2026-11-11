#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
int n;
ll m;
ll a[N],s[N];
int main(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	int j=1,ans=1;
	for(int i=1;i<=n;i++){
		while(a[i]*(i-j+1)-(s[i]-s[j-1])>m)j++;
		ans=max(ans,i-j+1);
	}cout<<ans;
	return 0;
}
