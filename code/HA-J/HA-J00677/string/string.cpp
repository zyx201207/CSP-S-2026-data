#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+7;
int n;
int a[N];
char c[N];
int ans;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	int l=1,r=n;
	while(l<r){
		if(c[l]!=c[r]) ans+=min(a[l],a[r]);
		if(a[l]>a[r]){
			a[l]-=a[r];
			r--;
		}
		else if(a[r]>a[l]){
			a[r]-=a[l];
			l++;
		}
		else{
			l++;
			r--;
		}
	}
	cout<<ans;
	return 0;
}