#include<bits/stdc++.h>
#define int long long
using namespace std;
int LADDM,n,m;
int a[(int)2e5+1];
int laand(int u,int v,int s){
	int MAX=-1;
	for(int i=1;i<v;i++){
		int ans=s&a[i];
		MAX=max(ans,laand(u-1,i,a[i]));
	}
	return MAX;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int MAX=-1;
	for(int i=1;i<=n;i++){
		MAX=max(MAX,laand(m,i,a[i]));
	}
	cout<<MAX;
}
