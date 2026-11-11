#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+5,logA=32;
int n,m;
int a[N];
vector<bool>last(N,1);
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(NULL);
	cin.tie(NULL);cout.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=logA-1;i>=0;i--){
		vector<bool>vis(N,0);
		int cnt=0;
		for(int j=1;j<=n;j++)
			if(a[j]&(1<<i)&&last[j]){
				cnt++;
				vis[j]=true;
			}
		if(cnt>=m) last=vis;
	}
	int cnt=0,ans=-1;
	for(int i=1;i<=n;i++){
		if(last[i]){
			if(ans==-1) ans=a[i];
			else ans=ans&a[i];
			cnt++;
		}
		if(cnt==m){
			cout<<ans;
			return 0;
		}
	}
	return 0;
}
