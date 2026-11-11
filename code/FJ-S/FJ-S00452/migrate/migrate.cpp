#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,d,a[5005],b[5005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>t>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		int ans=0;
		for(int i=1;i<n-2;i++){
			int b[n];
			for(int j=1;j<=n;j++) b[j]=0;
			queue<int> q;
			bool flag[5005];
			for(int j=1;j<=n;j++) flag[j]=0;
			q.push(i);
			while(!q.empty()){
				int cur=q.front();
				q.pop();
				bool flag2[5005];
				for(int j=1;j<=n;j++) flag2[j]=0;
				for(int j=cur+1;j<=n;j++) if(!flag[j]&&a[j]-cur<=d){
					q.push(j);
					b[cur]++,flag2[j]=1;
				}for(int j=1;j<=n;j++) flag[j]=flag[j]||flag2[j];
			}for(int j=i;j<=n;j++) if(b[j]==2) ans++;
		}cout<<ans<<"\n";
	}return 0;
}
