#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5; 
int n,a[N],ans;
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<n;++i){
		cin>>a[i]>>c[i];
	}
	int l=0,r=n-1;
	while(l<=r){
		if(a[l]==a[r]&&c[l]==c[r]){
			++l;--r;
			continue;
		}
		if(a[l]==a[r]&&c[l]!=c[r]){
			ans+=a[l];	
			++l;--r;
			continue;
		}
		if(a[l]>a[r]&&c[l]==c[r]){
			a[l]-=a[r];
			--r;
			continue;
		}
		if(a[r]>a[l]&&c[l]==c[r]){
			a[r]-=a[l];
			++l;
			continue;
		}
		if(a[l]>a[r]){
			ans+=a[r];
			a[l]-=a[r];
			--r;
			continue;
		}
		if(a[r]>a[l]){
			ans+=a[l];
			a[r]-=a[l];
			++l;
			continue;
		}
	}
	cout<<ans;
	return 0;
}
