#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],s[N],ans;
int calc(int i,int l){
	return a[i]*(i-l)-(s[i-1]-s[l-1]);
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	
	for(int i=1,j=1;i<=n;i++){
		while(j<i&&calc(i,j)>m)j++;
		ans=max(ans,i-j+1);
	}
	cout<<ans;
}
