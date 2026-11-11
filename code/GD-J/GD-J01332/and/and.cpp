#include <bits/stdc++.h>
using namespace std;
#define int long long
const int maxn=2e5+5;
int n,a[maxn],m,ans;
bool cmp(int x,int y){
	return x>y;
}
bool flag=0;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]!=i-1) flag=1;
	}
	if(m==1){
		for(int i=1;i<=n;i++) ans=max(ans,a[i]);
		cout<<ans;
	}
	else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				int p=a[i]&a[j];
				ans=max(p,ans);
			}
		}
		cout<<ans;
	}
	else if(n==m){
		ans=a[1];
		for(int i=1;i<=n;i++) ans=ans&a[i];
		cout<<ans;
	}
	else if(m==n-1){
		int sum=a[1];
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				else sum=sum&a[i];
			}
		}
		cout<<sum;
	}
	else if(flag==0) cout<<n-m;
	else{
		sort(a+1,a+1+n,cmp);
		ans=a[1];
		for(int i=2;i<=m;i++){
			int p=ans&a[i];
			if(p==0)continue;
			else ans=p;
		}
		cout<<ans;
	}
	return 0;
}
