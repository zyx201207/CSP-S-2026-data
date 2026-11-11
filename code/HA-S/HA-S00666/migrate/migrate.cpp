#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[2000005];
int tu[5005][5005];
vector<int>xu[5005];
int w=0;
int maxx=INT_MAX;
int d;
void dfs(int l,int r,int ci){
	if(l==r){
		if(ci<maxx){
			maxx=ci;
			w=1;
		}
		else if(ci==maxx)w++;
		return;
	}
	for(int i = l+1;i<=r;i++){
		if(a[i]-a[l]<=d)dfs(i,r,ci+1);
		else break;
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--){
		int n;
		cin>>n>>d;
		int ans=0;
		for(int i = 1;i<=n;i++){
			cin>>a[i];
		}
		for(int i =1;i<=n;i++){
			for(int j = i+1;j<=n;j++){
				w=0;
				maxx=INT_MAX;
				dfs(i,j,0);
				if(w==2){
					ans++;
					//cout<<maxx<<"\n";
				}
			}
		}
		cout<<ans<<"\n";
		
		
	}
	return 0;
} 
