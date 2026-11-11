#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m,a[N],js,ans,c;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	int mx=0;
	for(int i=1;i<=n;i++){
		js=m,ans=1,c=0;
		for(int j=i;j>=1;j--){
			int c=abs(a[i]-a[j]);
			js-=c;
			if(js<=0){
				break;
			}
			ans++;
		}
		mx=max(mx,ans);
	}
	cout<<mx;
	return 0;
}
