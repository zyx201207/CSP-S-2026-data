#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin >> n >> m;
	vector<long long>a(n+1);
	for(int i=1;i<=n;i++) cin >> a[i];
	sort(a.begin()+1,a.end());
	vector<long long>pre(n+1);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	int ans=0;
	long long sum=0;
	for(int l=1,r=1;r<=n;){
		if(sum<=m) ans=max(ans,r-l+1),r++,sum=(r-l)*a[r]-pre[r-1]+pre[l-1];
		else sum-=(pre[r]-pre[l-1]-a[l]*(r-l+1)),l++;
	}
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
