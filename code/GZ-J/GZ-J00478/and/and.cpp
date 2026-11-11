//GZ-J00478 遵义航天高级中学 张煜皓
#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+4;
long long a[N];
long long m,n;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1){
		sort(a+1,a+n+1);
		cout<<a[n];
		return 0;
	}
	if(m==n){
		long long ans=a[1];
		for(int i=2;i<=n;i++){
			ans=(ans&a[i]);
		}
		cout<<ans; 
		return 0;
	}
	if(m==2){
		long long ans=-1e9;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				long long _and=(a[i]&a[j]);
				if(i!=j) ans=max(ans,_and);
			}
		}
		cout<<ans;
		return 0;
	}
	if(m==n-1){
		long long ans=-1e9;
		for(int i=1;i<=n;i++){
			long long cnt=a[1];
			for(int j=1;j<=n;j++){
				if(i!=j) cnt=(cnt&a[j]);
			}
			ans=max(cnt,ans);
		}
		cout<<ans;
		return 0;
	}
	cout<<n;
	return 0;
}

