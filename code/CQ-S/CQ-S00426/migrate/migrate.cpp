#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,t;
int n,d;
int x[2000005],ll[2000005],rr[2000005],lmx[2000005],rmx[2000005];
namespace zrw1_10{
	int dp[5005],cnt[5005];
	int main(){
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				dp[j]=1e18;
				cnt[j]=1;
			}
			dp[i]=0;
			cnt[i]=1;
			for(int j=i+1;j<=n;j++){
				for(int k=j-1;k>=i;k--){
					if(x[j]-x[k]>d)break;
					if(dp[j]>dp[k]+1){
						dp[j]=dp[k]+1;
						cnt[j]=cnt[k];
					}
					else if(dp[j]==dp[k]+1){
						cnt[j]+=cnt[k];
					}
				}
				if(cnt[j]==2){
					ans++;
//					cout<<i<<" "<<j<<'\n';
				}
			}
		}
		return ans;
	}
}
void sl(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	if(c<=10){
		cout<<zrw1_10::main()<<'\n';
		return ;
	}
	for(int i=1;i<=n;i++){
		int l=i,r=n,ans=0;
		while(l<=r){
			int mid=(l+r)>>1;
			if(x[mid]-x[i]<=d){
				l=mid+1;
				ans=mid;
			}
			else{
				r=mid-1;
			}
		}
		rr[i]=ans;
	}
	for(int i=1;i<=n;i++){
		int l=1,r=i,ans=0;
		while(l<=r){
			int mid=(l+r)>>1;
			if(x[i]-x[mid]<=d){
				r=mid-1;
				ans=mid;
			}
			else{
				l=mid+1;
			}
		}
		ll[i]=ans;
	}
	for(int i=1;i<=n;i++){
		lmx[i]=0;
		if(rr[ll[i]]==i){
			lmx[i]+=lmx[ll[i]];
		}
		lmx[i]+=1;
	}
	for(int i=n;i>=1;i--){
		rmx[i]=0;
		if(ll[rr[i]]==i){
			rmx[i]+=rmx[rr[i]];
		}
		rmx[i]+=1;
	}
//	for(int i=1;i<=n;i++){
//		cout<<lmx[i]<<" "<<rmx[i]<<'\n'; 
//	}
//	cout<<'\n';
	int ans=0;
	for(int i=1;i<=n;i++){
		int lid=rr[i]-2,midd=rr[i]-1,rid=rr[i];
		if(lid<i)continue;
		int l=rr[i]+1,r=n,ans1=n+1,ans2=0,ans3=0;
		while(l<=r){
			int mid=(l+r)>>1;
			if(x[mid]-x[lid]>d){
				ans1=mid;
				r=mid-1;
			}
			else{
				l=mid+1;
			}
		}
		l=rr[i]+1,r=n;
		while(l<=r){
			int mid=(l+r)>>1;
			if(x[mid]-x[midd]<=d){
				ans2=mid;
				l=mid+1;
			}
			else{
				r=mid-1;
			}
		}
//		cout<<i<<" "<<ans1<<" "<<ans2<<" "<<ans3<<'\n';
		ans+=max(0ll,ans2-ans1+1);
	}
	for(int i=1;i<=n;i++){
		int id=rr[i]-1;
		int lid=ll[i],rid=rr[id];
		if(i>=id)continue;
//		cout<<i<<"/"<<id<<'\n';
//		cout<<ans<<'\n';
		ans+=max(rmx[id]-2,0ll);
//		cout<<ans<<'\n';
		if(x[id]-x[i-1]>d){
//			cout<<i<<"-"<<id<<'\n';
//			cout<<ans<<'\n';
			ans+=(lmx[i]-1)*(rmx[id]);
//			cout<<ans<<'\n';
		}
	}
	cout<<ans<<'\n';
	return ;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		sl();
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

0 1
2 3
-1 2

0 1
6 4
-3 0 1 2 3 4

0 1
6 3
0 1 2 3 4 7

0 1
5 3
4 6 7 8 10

0 1
7 666666666666666663
-1000000000000000000 -555555555555555558 -111111111111111116 111111111111111105 333333333333333326 555555555555555547 999999999999999989

*/
