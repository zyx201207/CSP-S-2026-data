#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[500005];
int d[300005];
int vis[300005];
vector<int> mp[300005];
bool check(int l,int r,int x){
	return mp[x][lower_bound(mp[x].begin(),mp[x].end(),l)-mp[x].begin()]>r; 
}
int bs(int l,int r,int x){
	int ans=l;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(l,mid,x)){
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	return ans;
}
int vis2[500005];
int vis3[600005];
int d2[500005];
int ans12[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	memset(vis,-1,sizeof(vis));
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mp[a[i]].push_back(i);
	}
	if(n<=6000){
		for(int i=1;i<=n;i++){
			memset(d,0,sizeof(d));
			memset(vis2,0,sizeof(vis2));
			for(int j=i;j<=n;j++){
				if(!vis2[a[j]]) vis2[a[j]]=j;
				else d[vis2[a[j]]]--,d[j]++,vis2[a[j]]=0;
			}
			for(int j=i;j<=n;j++) d[j]+=d[j-1],ans12[a[j]]+=(d[j]>=0?0:-1);
		}
		for(int i=1;i<=n;i++) ans12[a[i]]+=i;
		for(int i=1;i<=m;i++) cout<<ans12[i]<<' ';
		return 0;
	}
	int temp=-1;
	for(int i=1;i<=n;i++){
//		if(vis[a[i]]==0){
//			vis[a[i]]=i;
//			continue;
//		}
		if(i<=temp){
			d[a[i]]+=temp-i+1;
			vis[a[i]]=0;
			continue;
		}
		int tmp=bs(i+1,n,a[i]);
		cout<<tmp<<'\n';
		temp=tmp;
		d[a[i]]+=(tmp-i+1);
		vis[a[i]]=0;
	}
	for(int i=1;i<=m;i++) cout<<d[i]<<' ';
	return 0;
}

/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
