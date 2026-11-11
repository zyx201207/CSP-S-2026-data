#include<bits/stdc++.h>
using namespace std;
long long n,m,a[100005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++){
			ans=ans and a[i];
		}
		cout<<ans;
		return 0;
	}else{
		int ans=-1;
		for(int i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;
		return 0;
	}
	return 0;
}
