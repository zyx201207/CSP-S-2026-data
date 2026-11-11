#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int n,m;
int a[N],d[N],pre[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++){
		d[i]=a[i+1]-a[i];
	}
	for(int i=n-1;i>=1;i--){
		pre[i]=pre[i+1]+d[i];
	}
	int sum=0,mx=1;
	int l=1,r=1;
	while(r<=n){
		if(sum+(r-l+1)*d[r]<=m){
			sum+=(r-l+1)*d[r];
			r++;
			if(r>n) break;
			mx=max(mx,r-l+1);
		}else{
			while(sum+(r-l+1)*d[r]>m){
				if(l==r){
					if(d[r]>m){
						cout<<mx;
						return 0;
					}else{
						break;
					}
				}
				sum-=(pre[l]-pre[r]);
				l++;
			}
		}
	}
	cout<<mx;
	return 0;
} 
