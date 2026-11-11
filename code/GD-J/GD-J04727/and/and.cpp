#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,ans=0;
int a[200001][31],vis[200001];
signed main(){
	freopen("and.in","r",stdin);
	freopen("ans.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int t,len=0;
		cin>>t;
		while(t){
			a[i][++len]=t%2;
			t/=2;
		}
	}
	for(int i=30;i>=1;i--){
		int sum=0;
		for(int j=1;j<=n;j++)if(a[j][i]==1&&!vis[j])sum++;
		if(sum>=m){
			ans+=1<<(i-1);
			for(int j=1;j<=n;j++)if(a[j][i]==0&&!vis[j])vis[j]=1;
		}
	}
	cout<<ans;
}
