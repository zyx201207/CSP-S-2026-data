#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
const int N=5e5+10;
int a[N],b[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	bool ALL2=0;
	cin>>n>>m;
	//vector<vector<int>>dp(n+10,vector<int>(m+10));//前i个数，花费为j的情况下的最长长度 
	map<int,int>mp;
	int mmm=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mp[a[i]]++;
		mmm=max(mmm,mp[a[i]]);
		dp[i][0]=mmm; 
	}
	int op=a[2]-a[1];
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]==op)ALL2=1;
		else{
			ALL2=0;
			break;
		} 
	}
	sort(a+1,a+1+n);
	if(ALL2){//30
		int ans=1;
		for(int i=n-1;i>=1;i--){
			m-=(a[n]-a[i]);
			if(m<0)break;
			ans++;
		}
		cout<<ans;
	}else{
		int ans=2;
		for(int i=1;i<=n-ans+1;i++){
			for(int i=1;i<=n;i++){
				b[i]=a[i];
			}
			int c=m;
			int j=2;
			int f=0;
			while(c>=0 and j<=n-i+1){
				for(int k=1;k<i+j-1;k++){
					c-=(b[j]-b[k]);
					if(c<0){
						f=1;
						break;
					}
					b[k]=b[j];
				}
				if(f==1)break;
				j++;
			}
			ans=max(ans,j-1);
		}
		cout<<ans;
	}
	/*
	else{
		for(int i=1;i<=n;i++){
			for(int j=0;j<=m;j++){
				int W=a[i]-a[i-1];
				dp[i][j]=max({dp[i][j],dp[i-1][j-W]+1});
			} 
		}
	}
	*/
	return 0;
} 
