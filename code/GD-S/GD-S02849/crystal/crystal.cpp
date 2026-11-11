#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],ans,d;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	int flag=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>2&&a[i]-a[i-1]!=d)flag=1;
		if(i>1)d=a[i]-a[i-1];
	}
	sort(a+1,a+n+1);
	if(n<=5000){
		int p=0;
		for(int i=1;i<=n;i++){
			int sum=0;
			for(int j=i-1;j>p;j--){
				if(sum+a[i]-a[j]>m){
					p=j;
					break;
				}
				sum+=a[i]-a[j];
			}
			ans=max(ans,i-p);
		}
		cout<<ans;
		return 0;
	}
	if(!flag){
		int ans=1;
		for(int i=2;i<=n;i++){
			int l=1,r=i-1,res=0;
			while(l<=r){
				int mid=l+r>>1;
				if(d*((i-mid+1)*(i-mid)/2)>m){
					res=mid;
					l=mid+1;
				}
				else r=mid-1;
			}
			ans=max(ans,i-res);
		}
		cout<<ans;
	}
	return 0;
} 	
