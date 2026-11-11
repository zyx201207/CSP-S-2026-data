#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e5+9;
int n,l,r,a[N],sum;
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n;
	l=1,r=n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	while(l<=r){
		if(a[l]<=a[r]){
			if(c[l]!=c[r]) sum+=a[l];
			a[r]-=a[l];
			l++;
		}
		else{
			if(c[l]!=c[r]) sum+=a[r];
			a[l]-=a[r];
			r--;
		}
	}
	cout<<sum;
	return 0;
}
