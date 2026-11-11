#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N],last[N],h[N],cnt[N]; 
bool vis[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		if(h[a[i]]) last[i]=h[a[i]];
		else last[i]=0;
		h[a[i]]=i;
	}
//	for(int i=1;i<=n;i++) cout<<last[i]<<' ';
	cout<<'\n';
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) vis[j]=false;
		for(int j=i;j<=n;j++){
			if(vis[a[j]]){
				for(int k=last[j];k<=j-1;k++) vis[a[k]]=false;
			}
			vis[a[j]]=true;
//			cout<<i<<' '<<j<<'\n';
//			for(int k=1;k<=m;k++) cout<<vis[k]<<' ';
//			cout<<'\n';
		}
		for(int j=1;j<=m;j++) cnt[j]+=(vis[j]==true); 
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<' ';
}
