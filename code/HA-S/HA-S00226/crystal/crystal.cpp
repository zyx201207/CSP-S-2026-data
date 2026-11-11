#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500005;
int n,m;
int a[N];
int s[N];
int ans=-1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	//cost_j_i=(i-j+1)*a[i]-(s[i]-s[j])-a[j];
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		int ff=1;
		while(l<r){
			int j=(l+r)/2;			
			int cost=(i-j+1)*a[i]-(s[i]-s[j])-a[j];
			if(cost>m){
				l=j+1;
			}
			else if(cost<m){
				r=j;
				ff=i-j+1;
			}
			else {
				ff=i-j+1;
				break;
			}
		}
		ans=max(ans,ff);
	}
	cout<<ans;
	return 0;
} 
