#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+7;
int n;
ll m,a[N],d[N];
ll calc(int l,int r,ll mx){
	return mx*(r-l+1)-(d[r]-d[l-1]);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) d[i]=d[i-1]+a[i];
	int res=0;
	for(int i=1,r=0;i<=n;i++){
		while(r+1<=n && calc(i,r+1,a[r+1])<=m) r++;
		res=max(res,r-i+1);
	}cout<<res;
}
