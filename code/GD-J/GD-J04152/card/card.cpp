#include<bits/stdc++.h>
using namespace std;
int n,a[500005],m,lat[300005],t[500005],nxt[500005];
int sum[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=n;i>0;i--){
		if(lat[a[i]]) nxt[i]=lat[a[i]];
		t[i]=1,lat[a[i]]=i;
	}
	for(int i=1;i<=n;i++){
		if(nxt[i]) t[nxt[i]]+=t[i];
		else sum[a[i]]+=t[i],t[i+1]+=t[i];
	}
	for(int i=1;i<=m;i++) cout<<sum[i]<<" ";
}
