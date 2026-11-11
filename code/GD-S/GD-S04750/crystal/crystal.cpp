#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int a[N];
int n,m;
int sum;
int ans,flag1=1,flag2=1,x;
int check(int k,int cnt){
	sum=0;
	for(int i=k;i>=1;i--){
		if(cnt-(a[k]-a[i])>=0){
			cnt-=(a[k]-a[i]);
			sum++; 
		}
	}
	if(sum>=ans) return 1;
	else return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		if(a[i]!=i) flag1=0;
		if(i==2) x=a[i]-a[i-1];
		if(i!=1&&a[i]-a[i-1]!=x) flag2=0;	
	}
	if(flag1||flag2){
		int l=1,r=n;
		while(l<=r){
			int mid=(l+r)/2;
			if(check(mid,m)){
				l=mid+1;
				ans=max(ans,sum);
			}else r=mid-1;
		}cout<<ans<<"\n";
		return 0;
	}
	ans=0;
	for(int i=1;i<=n;i++){
		int t=m;
		sum=0;
		for(int j=i;j>=1;j--){
			if(t-a[i]+a[j]>=0){
				t-=a[i]-a[j];
				sum+=1;
			}else{
				break;
			}
		}ans=max(sum,ans);
	}cout<<ans<<"\n";
	return 0;
}
