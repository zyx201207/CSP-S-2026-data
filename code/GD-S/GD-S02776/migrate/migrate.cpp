#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[2000005];
struct nd{
	int l;
	int r;
};
unordered_map<int,int> mp;int n,d;
int ans=0;
int minn=1e9;
void dfs(int u,int v,int step){
	//cout<<u<<endl;
	if(u==v){
		if(step==minn) ans++;
		if(step<minn){
			minn=step;
			ans=1;
		}
		return;
	}
	if(u>v) return;
	for(int x=u+1;x<=u+d && x<=v;x++){
		if(mp.count(x)>=1){
			dfs(x,v,step+1);
		}
	}

}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c;cin>>c;
	int t;cin>>t;
	while(t--){
		//memset(cnt,0,sizeof(cnt));
		mp.clear();
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++) mp[a[i]]=i;
		int sum=0;
		for(int l=1;l<=n;l++){
			for(int r=l+1;r<=n;r++){
				ans=0;
				minn=1e9;
				dfs(a[l],a[r],0);
				
				if(ans==2){//cout<<l<<" "<<r<<endl;  
					sum++;
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
