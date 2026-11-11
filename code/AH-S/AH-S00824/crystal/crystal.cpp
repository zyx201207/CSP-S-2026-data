#include<bits/stdc++.h>
using namespace std; 
#define ll long long
#define MAXN 2000005
ll n,m;
ll a[MAXN];
ll dp[MAXN];
int ans;
bool cmp(int a,int b){
    return a<b;
} 
bool check(int id){
	for(int i=id;i<=n;i++){
		if(id*a[i]-(dp[i]-dp[i-id])<=m){
	        return 1;
	    }
	}
    return 0; 
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	scanf("%lld%lld",&n,&m);
	dp[0]=0;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		dp[i]=dp[i-1]+a[i];
	} 
	int l=1,r=n,mid,tmp=0;
	while(l<r){
		if(tmp>20){
			break;
		}
	    mid=(l+r)>>1;
	    if(check(mid)){
		    l=mid;
		}else{
			r=mid-1;
		}
		tmp++;
	}
	ans=l;
	cout<<ans<<"\n";
	return 0;
}
//Oct31==Dec25?
/*
5 8 
-3 -1 2 2 7
*/
/*
5 5 
1 2 4 8 9
*/

