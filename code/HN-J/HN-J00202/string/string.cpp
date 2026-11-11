#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+5;
int n;
int a[N];
char nc[N];
void solve(){
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>nc[i];
	int l=1,r=n;
	ll ans=0;
	while(l<=r){
		if(nc[l]==nc[r]){
			if(a[l]==a[r]) l++, r--;
			else if(a[l]>a[r]) a[l]-=a[r--];
			else if(a[l]<a[r]) a[r]-=a[l++];
		}else{
			ans+=min(a[l],a[r]);
			if(a[l]==a[r]) l++, r--;
			else if(a[l]>a[r]) a[l]-=a[r--];
			else if(a[l]<a[r]) a[r]-=a[l++];
		}
		
	}
	cout<<ans<<endl;
	return ;
}
/*
3
2 a
2 b
1 c
*/
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int T=1; //cin>>T;
	while(T--) solve();
	return 0;
} 
