#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
int c,t,n,d,ans;
int dp[N],num[N];
int a[N],last[N];
void work(){
	cin>>n>>d;
	int ans=0;
	for(int i=1;i<=n;i++)  last[i]=0;
	for(int i=1;i<=n;i++){
    	cin>>a[i];
    	int j=i-1;
    	while(a[i]-a[j]<=d&&j!=0){
    		j--;
		}
		last[i]=j+1;
	}
	for(int id=1;id<n-1;id++){
		for(int i=id;i<=n;i++)  dp[i]=num[i]=0;
		for(int i=id+1;i<=n;i++){
			int j=max(id,last[i]);
			if(last[i]<=id)  num[i]=1;
			dp[i]=dp[j]+1;
			while(dp[j]==dp[i]-1){
				num[i]+=num[j];
				j++;
			}
			if(num[i]==2)  ans++;
		}
	}
	cout<<ans<<endl;
	return;
}
signed main(){
	freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)  work();
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
*/
