#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005];
int qian[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i =1;i<=n;i++){
		cin>>a[i];
	}
	
	sort(a+1,a+1+n);
	for(int i =1;i<=n;i++)qian[i]=qian[i-1]+a[i];
	int ans=1;
	for(int i = 2;i<=n;i++){
		int l=1,r=i-1;
		int now=i;
		while(l<=r){
			int mid=(l+r)/2;
			if(a[i]*(i-mid)-(qian[i-1]-qian[mid-1])<=m){
				now=mid;
				r=mid-1;
			}
			else l=mid+1;
			
			
			
		}
		ans=max(ans,i-now+1);
	}
	cout<<ans;
	
	return 0;
} 
