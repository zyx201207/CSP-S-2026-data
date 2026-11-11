#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int n;
long long m,a[maxn];
int ans;
bool check(int x)
{
	int cnt=1,l=x-1;
	long long tot=0;
	while(l>=1 && a[x]-a[l]+tot<=m)
		tot+=a[x]-a[l],l--,cnt++;
	if(cnt>ans) {
		ans=cnt;
		return 1;
	}
	return 0;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	int l=1,r=n;
	while(l<=r){
		int mid=l+(r-l)/2;
		if(check(mid)) l=mid+1;
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}

