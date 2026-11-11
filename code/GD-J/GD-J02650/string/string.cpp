#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+7;
int n;
int a[N];
char c[N];
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i]>>c[i];
	int l=1,r=n,ans=0;
	while(l<r){
		if(a[l]>=a[r]){
			int k=a[l]-a[r];
			if(c[l]!=c[r]) ans+=a[r];
			a[l]=k;
			a[r]=0;
			r--;
			if(k==0) l++;
		}else{
			int k=a[r]-a[l];
			if(c[l]!=c[r]) ans+=a[l];
			a[l]=0;
			a[r]=k;
			l++;
			if(k==0) r--;
		}
	}
	cout<<ans;
	return 0;
}
