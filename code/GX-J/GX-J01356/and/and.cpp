#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e5+10,M=2000+10;
int n,m,ans;
int a[N];
int sum[N];

void dfs(int k,int num,int sum){
	if(k==n+1){
		if(num==m)ans=max(ans,sum);
		return;
	}
	dfs(k+1,num,sum);
	if(sum!=0)dfs(k+1,num+1,sum&a[k]);
	else dfs(k+1,num+1,a[k]);
}

signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    
    if(m==n-1){
		sum[0]=(1<<35)-1,sum[1]=a[1];
		for(int i=2;i<=n;i++)sum[i]=sum[i-1]&a[i];
		
		int num=a[n];ans=sum[n-1];
		for(int i=n-1;i>=1;i--){
			ans=max(ans,num&sum[i-1]);
			num&=a[i];
		}
	}
	else dfs(1,0,0);
	cout<<ans;
    return 0;
}
