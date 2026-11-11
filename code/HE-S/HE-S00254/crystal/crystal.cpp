#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define endl '\n'
#define int ll
const int N=5e5+5;
int n,m,a[N];
int s[N],ans;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
//		for(int j=1;j<=i;j++){
//			if(a[i]*(i-j+1)-(s[i]-s[j-1])<=m){
//				ans=max(ans,i-j+1);
//			}
//		}
		int l=0,r=i-1,res=i-1;
		//res=j-1
		while(l<=r){
			int mid=(l+r)>>1;
			int val=m-a[i]*(i-(mid+1)+1)+s[i];
			if(s[mid]<=val){
				res=mid;
				r=mid-1;
			}else{
				l=mid+1;
			}
		}
		int j=res+1;
		ans=max(ans,i-j+1);
		//a[i]*(i-j+1)-s[i]+s[j-1]<=m
		//s[j-1]<=m-a[i]*(i-j+1)+s[i]
	}
	cout<<ans;
	return 0;
}
//crystal
