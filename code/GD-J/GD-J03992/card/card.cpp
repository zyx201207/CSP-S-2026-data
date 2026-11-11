#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],pos[500005],posn[300005];
long long cnt[300005];
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=n;i>0;i--){
		pos[i]=posn[a[i]];
		if(!posn[a[i]])posn[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		bool vis[300005]={};
		for(int j=i;j<=n;j++){
			if(!vis[a[j]])cnt[a[j]]++,vis[a[j]]=true;
			if(pos[j])j=pos[j];
		}
	}
	for(int i=1;i<=m;i++){
		cout<<cnt[i]<<" ";
	}
}
