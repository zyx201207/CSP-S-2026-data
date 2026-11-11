#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e5+10;
int n,ans=1;
ll m,a[maxn];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int p=1; ll sum=0;
	for(int i=2;i<=n;i++){
		sum+=(a[i]-a[i-1])*(i-p);
		while(p<i&&sum>m) sum-=(a[i]-a[p++]);
		ans=max(ans,i-p+1);
	}
	cout<<ans<<'\n';
	fclose(stdin); fclose(stdout);
	return 0;
}
