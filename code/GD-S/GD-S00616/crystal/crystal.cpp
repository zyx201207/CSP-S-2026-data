#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int a[N];
//int dp[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		//dp[i]=1;
	} 
	if(m==0){
		cout<<1;
		return 0;
	}
	sort(a+1,a+n+1);
	//int ans=0;
	int l=1;
	while(m>0){
		a[l]++;
		m--;
		if(a[l+1]>=a[l]){
			l=1;
		}else{
	        /*for(int i=1;i<=n;i++){
	 	        cout<<a[i]<<' ';
	        }
	        cout<<'\n';*/
			l++;
			//ans=max(l,ans);
		}
	}
	/*for(int i=1;i<=n;i++){
		cout<<a[i]<<' ';
	}*/
	int ans=0;
	/*for(int i=1;i<=n;i++){
		for(int j=1;j<i;j++){
			if(a[i]==a[j]){
			cout<<i<<' '<<j<<' ';
			dp[i]=max(dp[i],dp[j]+1);
			ans=max(dp[i],ans);
			cout<<dp[i]<<'\n';
			}
		}
	}*/
	int last=1,cnt=0;
	int u=0;
	for(int i=1;i<=n;i++){
		if(a[i]==a[last]){
			cnt++;
			ans=max(cnt,ans);
		}else{
			last=i;
			cnt=1;
		}
	}
	//cout<<dp[n];
	cout<<ans;
	return 0;
} /*
5 8
-3 -1 2 2 7
*/
// 3 3845
