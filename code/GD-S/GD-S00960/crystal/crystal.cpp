#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
const int N=5e5+5,M=1e2+5;
const int INF=0x3f3f3f3f,MOD=1e9+7;
typedef long long LL;
int n,ans;
LL m,a[N];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	LL cnt=0;
	int l=1,r=1;
	while(l<=r){
		while(r+1<=n&&cnt+(a[r+1]-a[r])*(r-l+1)<=m)cnt+=(a[r+1]-a[r])*(r-l+1),r++;
		ans = max(ans,r-l+1);
		cnt-=a[r]-a[l],l++; 
	}
	cout<<ans;
	return 0;
}

