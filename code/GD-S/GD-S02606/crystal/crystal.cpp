#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+10;
int n,m;
int a[maxn];
int all[maxn];
signed main(){
    freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=1;
	sort(a+1,a+n+1);
	all[1]=0;
	int k=1;
	for(int i=2;i<=n;i++){
		all[i]=all[i-1]+(i-k)*(a[i]-a[i-1]);
		if(all[i]<=m){
			ans=max(ans,i-k+1);
		}else{
			while(all[i]>m&&k<n){
				all[i]-=(a[i]-a[k]);
				k++;
			}
			ans=max(ans,i-k+1);
		}
	}
	cout<<ans;
	return 0;
}
