#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200010],ans;char c[200010];
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	for(int i=1,j=n;i<j;){
		if(c[i]==c[j]){
			int t=min(a[i],a[j]);
			a[i]-=t;
			a[j]-=t;
			if(a[i]==0)i++;
			if(a[j]==0)j--;
		}else{
			int t=min(a[i],a[j]);
			ans+=t;
			a[i]-=t;
			a[j]-=t;
			if(a[i]==0)i++;
			if(a[j]==0)j--;
		}
	}
	cout<<ans;
}
#undef int
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
//	int t;
//	cin>>t;
//	while(t--){
		solve();
//	}
	return 0;
}
