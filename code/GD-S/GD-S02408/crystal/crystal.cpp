#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m,ans;
int a[N];
int b[N];
signed main(){
	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);

	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)b[i]=b[i-1]+a[i];
	int l=1,sum=0;
	for(int i=2;i<=n;++i){
		sum+=(i-l)*(a[i]-a[i-1]);
		while(sum>m){
			sum-=(a[i]-a[l-1]);
			l++;
		}
		ans=max(ans,(i-l+1));
	}
	cout<<ans;
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
