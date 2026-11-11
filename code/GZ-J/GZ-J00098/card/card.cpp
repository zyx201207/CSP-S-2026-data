//毕节七星关东辰实验学校 刘杰 GZ-J00098
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MXN=5e5+10,MXM=3e5+10;
int ans[MXM];
int n,m;
int a[MXN],h[MXN];
int pre[MXM]={};
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		h[pre[a[i]]]=i;
		pre[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		if(h[i]==0)    h[i]=i;
		cout<<h[i]<<endl;
	}
	for(int i=1;i<=n;i++){
		vector<int> add;
		for(int j=i;j<=n;j++){
			add.push_back(a[j]);
			while(j<=n&&j!=h[j]){
				j=h[j];
			}
		}
		for(int j=0;j<add.size();j++){
			ans[add[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<" ";
	}
} 
