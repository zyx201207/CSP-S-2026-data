#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],b[N],sum,ans,maxx=-1e9;
bool cmp(int x,int y){
	return x>y;
}
set<int>s;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n-1;i++){
		ans=0;
		sum=0;
		for(int j=i;j<=n;j++){
			if(sum+a[i]-a[j]<=m)sum+=a[i]-a[j],ans++;
		}
		maxx=max(maxx,ans);
	}
	if(maxx<0){
		cout<<1;
		return 0;}
	cout<<maxx;
	return 0;
}
