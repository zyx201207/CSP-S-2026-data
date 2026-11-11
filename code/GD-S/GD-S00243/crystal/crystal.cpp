#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N=1e6+5;
int a[N],n,s[N],m,res;
bool check(int l,int r){
	return (r-l+1)*a[r]-(s[r]-s[l-1])<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1); 
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i,ans=-1;
		while(l<=r){
			int mid=(l+r)/2;
			if(check(mid,i)){
				r=mid-1;
				ans=mid;
			}else{
				l=mid+1;
			}
		}	
		if(ans==-1)continue;
		res=max(res,i-ans+1);
	}
	cout<<res<<'\n';
}
/*
5 5
1 2 4 8 9
*/ 
/*
5 8
-3 -1 2 2 7
*/
