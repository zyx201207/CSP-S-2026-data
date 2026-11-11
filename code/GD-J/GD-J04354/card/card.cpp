#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
int n,m;
int a[N];
int vis[N];
int vis2[N];
void found(int num){
	int j=0;
	for(int i=num;i<=n;i++){
		if(vis[a[i]]){
			j=i;
		}
		else vis[a[i]]=1;
	}
	if(j==0) return;
	if(j==n){
		for(int i=num;i<=n;i++){
			vis[a[i]]=0;
		}
		return;
	}
	for(int i=num;i<j;i++){
		vis[a[i]]=0;
	}
	for(int i=j;i<=n;i++){
		vis[a[i]]=1;
	}
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		memset(vis,0,sizeof vis);	
		found(i);
		for(int j=1;j<=m;j++){
			if(vis[j]!=0){
				vis2[j]++;
			}
		}
	}
	for(int i=1;i<=m;i++){
		cout<<vis2[i]<<" ";
	}
	return 0;
}

