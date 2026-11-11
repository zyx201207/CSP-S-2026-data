#include<bits/stdc++.h>
using namespace std;
#define int long long
long long a[200001];
char c[200001];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	while(l<=r){
		if(c[l]!=c[r]){
			if(a[l]>a[r]){
				ans+=a[r];
				a[l]-=a[r];
				r--;
			}else if(a[r]>a[l]){
				ans+=a[l];
				a[r]-=a[l];
				l++;
			}else{
				ans+=a[l];
				l++;
				r--;
			}
		}else{
			l++;
			r--;
		}
	}
	cout<<ans;
	return 0;
}
