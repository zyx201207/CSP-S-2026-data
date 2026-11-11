#include<bits/stdc++.h>
using namespace std;
long long n,m,it=1,sum,ans,a[500005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum+=a[i];
		while(a[i]*(i-it+1)-sum>m) sum-=a[it],it++;
		ans=max(ans,i-it+1);
	}
	cout<<ans;
	return 0;
} 
