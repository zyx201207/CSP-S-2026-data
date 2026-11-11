#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n;
long long m,a[N],s[N];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;++i)s[i]=s[i-1]+a[i];
	int ans=0;
	for(int i=1;i<=n;++i){
		int l=0,r=i-1;
		while(l<r){
			int mid=(l+r+1)>>1;
			if(mid*a[i]-(s[i-1]-s[i-1-mid])<=m){
				l=mid;
			}else{
				r=mid-1;
			}
		}
		ans=max(ans,l+1);
	}
	cout<<ans;
	return 0;
} 
