#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n,m;
int a[200010];
int maxx;
void dfs(int step,int now,int k){
//	cout<<step<<' '<<now<<' '<<k<<endl;
	if(k==m){
		if(now==(1<<30)-1)return;
		else maxx=max(now,maxx);
		return;
	}
	if(step>n)return;
	dfs(step+1,now&a[step],k+1);
	dfs(step+1,now,k);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(m==n-1){
		for(int i=1;i<=n;i++){
			int sum=(1<<31);
			for(int j=1;j<=n;j++){
				if(i!=j)
					sum&=a[j]; 
			}
			maxx=max(maxx,sum);
		}
		cout<<maxx;
		return 0;
	}
	dfs(1,(1<<30)-1,0);
	cout<<maxx;
	return 0;
}
