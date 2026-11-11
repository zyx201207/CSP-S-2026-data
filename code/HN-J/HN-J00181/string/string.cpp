#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+5;
int a[N],ans;
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i]>>c[i];
	int l=1,r=n;
	while(l<r){
		if(a[l]<a[r]){
			if(c[l]!=c[r])
				ans+=min(a[l],a[r]);
			a[r]-=a[l];
			l++;
		}else if(a[l]>a[r]){
			if(c[l]!=c[r])
				ans+=min(a[l],a[r]);
			a[l]-=a[r];
			r--;
		}else{
			if(c[l]!=c[r])
				ans+=min(a[l],a[r]);
			l++,r--;
		}
	}
	cout<<ans;
	return 0;
}
