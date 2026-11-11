#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int a[N],n,m,s[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	int ans=1;
	for(int i=2;i<=n;i++){
		int p=a[i];
		int l=1,r=i;
		while(l<=r){
			int j=(l+r)>>1;
			if((i-j+1)*p-(s[i]-s[j-1])<=m){
				ans=max(ans,i-j+1);
				r=j-1;
			}
			else l=j+1;
		}
	}
	cout<<ans;
	return 0;
}
