#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
long long n,m;
long long a[N];
long long ans=-1;
bool cmp(long long x,long long y){
	return x<y;
}
long long vis[N];
void dfs(long long cnt){
	for(int i=1;i<=n;i++){
		long long d=1;
		for(int j=i+1;j<=n&&i!=n;j++){
			if(vis[j]==vis[i]){
				d++;
			}
		}
		ans=max(ans,d);
		}
	if(cnt>=m){
		return;
	}
	for(int i=1;i<=n;i++){
		vis[i]++;
		dfs(cnt+1);
		vis[i]--;
	}
}
void S(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++)vis[i]=a[i];
	//for(int i=1;i<=n;i++)cout<<a[i]<<" ";
	dfs(0);
	cout<<ans<<endl;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int _=1;
	//cin>>_;
	while(_--)S();
	return 0;
}
