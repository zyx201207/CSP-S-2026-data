#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500010],pos[500010],vis[500010],ans[500010];
#undef int 
int main(){
	#define int long long
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	bool flag=true;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<a[i-1]){
			flag=false;
		}
		pos[a[i]]=i;
	}
	if(flag){
		for(int i=1;i<=m;i++){
			cout<<pos[a[i]]<<' ';
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j=max(pos[a[j]],j+1)){
			vis[a[j]]=1;
		}
		for(int j=1;j<=m;j++){
			ans[j]+=vis[j];
			vis[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
	return 0;
}
