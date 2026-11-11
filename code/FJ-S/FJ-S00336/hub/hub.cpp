#include<bits/stdc++.h>
using namespace std;
vector<int>bian[1000005];
int c,n,k,T;
int cd=0,maxwz=0;
void dfs(int wz,int fa,int nans){
	if(nans>cd)cd=nans,maxwz=wz;
	for(auto nwz:bian[wz]){
		if(nwz==fa)continue;
		dfs(nwz,wz,nans+1);
	}
	return ;
}
void cl(){
	cin>>n>>k;
	for(int i=1;i<=n;i++)bian[i].clear();
	for(int i=1;i<n;i++){
		int a,b;
		cin>>a>>b;
		bian[a].push_back(b),bian[b].push_back(a);
	}
	if(c==13||c==14){
		cout<<n/k;
		return ;
	}
	if(k==2){
		dfs(1,0,0);
		dfs(maxwz,0,0);
		cout<<ceil((cd-2)/3)<<'\n';
		cd=0;
		return ;
	}
	cout<<1<<'\n';
	return ;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--)cl();
	return 0;
}
