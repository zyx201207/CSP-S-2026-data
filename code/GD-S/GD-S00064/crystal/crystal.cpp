#include <bits/stdc++.h>
//#define ll long long
#define int long long
using namespace std;
const int N=5e5+10,inf=2e18;
int n,m,a[N],ans,cost;
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	ans=1;
	for(int i=1,p=1;i<=n;i++){
		if(i!=1)cost+=(a[i]-a[i-1])*(i-1-p+1);
		if(cost<=m)ans=max(ans,i-p+1);
		while(cost>m&&p+1<=i){
			cost-=a[i]-a[p++];
		}
	}
	cout<<ans;
	return 0;
} 
/*
hack:
9 6
1 2 4 8 9 15 16 17 18
ans:4
*/
