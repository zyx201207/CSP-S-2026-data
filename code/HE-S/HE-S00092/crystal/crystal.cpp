#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
const int N  =5*1e5+5;
int a[N];
bool check(int mid){
	int  k =0; 
	for(int i =1;i<=n;i++){
		if(a[i]>mid){
			break;
		}
		else{
			k=1ll*(1ll*k+1ll*(mid-a[i]));
		}
	}
	return 1ll*k<=1ll*m; 
}
void dfs(){
	int ank=0,ans=0;
	for(int i=1;i<=n;++i){
		//Ã¶¾ÙÉÏÏÞ 
		int k =0 ;
		ans=0;
		for(int j =i;j>=1;j--){
			
			k+=abs(a[j]-a[i]);
			ans++;
			if(k==m){
				break;
			}
			if(k>m)ans--;
		}
		ank = max(ank,ans);
	}
	cout<<ank;
	return ; 
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	
	int r=0;
	for(int i =1;i<=n;i++){
		cin>>a[i];
		r=max(r,a[i]);
	}
	sort(a+1,a+n+1);
	if(n<=5000){
		dfs();
		return 0;
	}
	int l =1;
	int maxn=0;
	while(l<=r){
		int mid(1ll*(l+r)/2);
		if(check(mid)){
			l=mid+1;
			maxn=max(maxn,l);
		}else{
			r=mid-1;
		}
	}
	int ans =0 ;
	for(int i =1;i<=n;i++){
		if(a[i]<=maxn-1){
			ans++;
		}
	}
	cout<<ans;
	return 0 ; 
}
