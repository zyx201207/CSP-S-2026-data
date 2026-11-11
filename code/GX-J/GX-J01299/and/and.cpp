#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,a[200005];
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==m){
		long long ans=a[1];
		for(int i=2;i<=n;i++) ans&=a[i];
		cout<<ans<<endl;
	}else if(m==1){
		long long ans=-100000;
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]&a[i]);
		}
		cout<<ans<<endl;
	}else if(m==2){
		long long ans=-100000;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				ans=max(ans,a[i]&a[j]);
		cout<<ans<<endl;
	}
	return 0;
}
