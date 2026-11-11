#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[200010];
int ans;
bool vis[200010];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int p=29;p>=0;p--){
		int res=0;
		for(int i=1;i<=n;i++){
			if(!vis[i]&&(a[i]>>p)&1) res++;
		}
		if(res>=m){
			ans+=(1<<p);
			for(int i=1;i<=n;i++){
				if(!((a[i]>>p)&1)) vis[i]=1;
			}
		}
	}
	cout<<ans<<"\n";
	return 0;
}

/*
5 3
31 3 1 15 7

*/