#include<bits/stdc++.h>
using namespace std;
long long n,m,a[50005],k,ans=0,ans1=1,u;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	if(n==1){
		cout<<1;
		return 0;
	} 
	for(int i=n;i>=1;i--){
		u=m,ans1=0;
			for(int j=i;j>=1;j--)
				if(u-a[i]+a[j]>=0) ans1++,u=u-a[i]+a[j];
		ans=max(ans,ans1);
	}
	cout<<ans;
    fclose(stdin);
	fclose(stdout);
	return 0;
}
