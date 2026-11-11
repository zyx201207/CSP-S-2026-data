#include <bits/stdc++.h>
#define zls rp++
#define ll long long
#define ull unsigned long long
using namespace std;
int n,h=0,ans=1;
ll a[500005],m,s[500005];
void work(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
		if(i<n&&a[i]==a[i+1])continue;
		while(h<i&&a[i]*(i-h)-(s[i]-s[h])>m)h++;
		ans=max(ans,i-h);
	}
	cout<<ans;
} 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	work();
	return 0;
}
