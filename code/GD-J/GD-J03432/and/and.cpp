#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
int n,a[N],m,ans;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1){
		for(int i=1;i<=n;i++) ans=max(ans,a[i]);
		cout<<ans;
	}else if(m==2){
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
	}else if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++) ans&=a[i];
		cout<<ans;
	}else if(m==n-1){
		ans=a[2];
		for(int i=3;i<=n;i++) ans&=a[i];
		for(int i=2;i<=n;i++){
			int t=a[1];
			for(int j=2;j<=n;j++){
				if(j==i) continue;
				else t&=a[j];
			}
			ans=max(ans,t);
		}
		cout<<ans;
	}else{
		ans=a[1];
		for(int i=2;i<=m;i++){
			ans=ans&a[i];
		}
		cout<<ans;
	}
	return 0;
}
