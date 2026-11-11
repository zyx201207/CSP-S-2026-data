#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
int a[200005];
char c[200005];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n,ans=0;
	while(l<r){
		if(l>=r)break;
		if(a[l]>=a[r]){
			a[l]-=a[r];
			if(c[l]==c[r]){
				r--;
			}
			else{
				ans+=a[r];
//				a[l]-=a[r];
				r--;
			}
		}
		else{
			a[r]-=a[l];
			if(c[l]==c[r]){
				l++;
			}
			else{
				ans+=a[l];
				l++;
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}
