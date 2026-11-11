#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500002];
int ans=1;
signed main(){
	freopen("crystal","r",stdin);
	freopen("crystal","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}	
	sort(a+1,a+1+n);
	int l=1,r=2,s=0;
	while(r<=n&&l<=r){		
		s+=(r-l)*(a[r]-a[r-1]);
		if(s<=m){
			r++;
		}
		else {
			while(s>=m){
				s=s-a[r]+a[l];
				l++;
			}
		}
		ans=max(ans,r-l);
	}
	cout<<ans;
	return 0;
}
