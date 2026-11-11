#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[212345],n,m;
void dfs(){
	
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1){
		sort(a+1,a+n+1,greater<int>());
		cout<<a[1]<<endl;
	}else if(m==2){
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,(a[i]&a[j]));
			}
		}
		cout<<ans<<endl;
	}else if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans=(ans&a[i]);
		}
		cout<<ans<<endl;
	}else if(m<=20&&n<=20){
		dfs();
	}
	
	return 0;
}
