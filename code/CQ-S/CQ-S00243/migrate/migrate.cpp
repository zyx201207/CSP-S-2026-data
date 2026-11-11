#include<bits/stdc++.h>
using namespace std;
int n;
long long d;
long long a[2000005];
long long s1[2000005],s2[2000005];
int cnt=0,cnt2=INT_MAX;
void dfs(int x,int t,int sum){
	if(sum>cnt2) return ;
	if(x>=t){
		if(sum<cnt2) cnt2=sum,cnt=1;
		else cnt++;
		return ;
	}
	for(int i=x+1;i<=t;i++){
		if(a[i]-a[x]>d) return ;
		dfs(i,t,sum+1);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int CC; cin>>CC;
	int T; cin>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		long long ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				cnt=0,cnt2=INT_MAX;
				dfs(i,j,0);
				if(cnt==2) ans++;
			}
		}
		cout<<ans<<endl;
//		long long ans=0;
//		for(int i=2;i<=n-1;i++){
//			if(a[i+1]>a[i-1]+d&&a[i-1]+d>=a[i]) s1[i]=s1[i-1]+1;
//			else s1[i]=0;
//		}
//		for(int i=n-1;i>=2;i--){
//			if(a[i-1]+d<a[i+1]&&a[i+1]-d<=a[i]) s2[i]=s2[i+1]+1;
//			else s2[i]=0;
//		}
////		for(int i=1;i<=n;i++) cout<<s1[i]<<' '; cout<<endl;
////		for(int i=1;i<=n;i++) cout<<s2[i]<<' '; cout<<endl;
//		for(int i=1;i<=n;i++){
//			int p1=upper_bound(a+1,a+1+n,a[i]+d)-a-1;
//			if(p1-i!=2) continue;
//			int p2=upper_bound(a+1,a+1+n,a[p1-1]+d)-a-1;
//			int p3=upper_bound(a+1,a+1+n,a[p1-2]+d)-a-1;
//			if(p2-i==3){
////				cout<<i<<' '<<p1<<' '<<p3<<' '<<p2<<endl;
//				if(p3>p1) ans+=(1+s1[i])*(s2[p2]+(p2-p3+1));
//				else ans+=(1+s1[i])*(s2[p2]+1);
////				cout<<i<<' '<<p2<<endl;
//				
//			}
//		}
//		cout<<ans<<endl;
	}
	return 0;
}
/*
0 1
6 3
1 4 7 8 9 11 12
*/
