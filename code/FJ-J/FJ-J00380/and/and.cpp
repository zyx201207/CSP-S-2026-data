#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200005];
bool vis[200005];
vector<int>vc[32];//包含2^i次方的数字下标集合
vector<int>now;//当前前i个交集 
vector<int>nw;//当前算出来的预期交集 
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		for(int j=30;j>=0;j--){
			if(a[i]&(1<<j)){
				vc[j].push_back(i);
			}
		}
	}
	int ans=0;
	bool flag=0;//交集中是否有元素 
	for(int j=30;j>=0;j--){
		if(!flag&&vc[j].size()>=m){
			flag=1;
			for(auto i:vc[j]){
				now.push_back(i);
				vis[i]=1;
			}
			ans+=(1<<j);
		}else if(flag){
			int cnt=0;
			nw.clear();
			for(auto i:vc[j]){
				if(vis[i]){
					cnt++;
					nw.push_back(i);
				}
			}
			if(cnt>=m){
				for(auto i:now){
					vis[i]=0;
				}
				now.clear();
				for(auto i:nw){
					now.push_back(i);
					vis[i]=1;
				}
				ans+=(1<<j);
			}
		}
	}
	cout<<ans;
	return 0;
}
