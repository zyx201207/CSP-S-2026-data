//crystal
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=5e5+7;
int a[maxn],p[maxn];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	
	int n,m;
	cin >> n >> m;
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		p[i]+=p[i-1]+a[i];
	}
	int l=1,r=1,ans=1;
	while(l<=r&&r<=n){
	
		if((r-l+1)*a[r]-(p[r]-p[l-1])<=m){
			ans=max(ans,r-l+1);
//			cout << "chk:" << l << ' ' << r << endl;
			r++;
		}else{
			l++;
		}
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
