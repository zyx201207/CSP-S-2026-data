#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500010];
bool cmp(int x,int y){return x<y;}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1,cmp);
	int t=m;
	int maxn=-999,ans=1;
	for(int i=n;i>=2;i--){
		int l=ans;
		while(m>0&&i-l>=1){
			if(a[i]-a[i-l]>m)break;
			else m-=a[i]-a[i-l],ans++,l++;
		}
		m+=(a[i]-a[i-1])*(ans-1);
		maxn=max(ans,maxn);
		ans=max(ans-1,1ll*(1));
	}
	cout<<maxn;
	return 0;
} 
