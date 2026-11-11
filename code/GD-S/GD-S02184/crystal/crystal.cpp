#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+9;
int a[N];
int vis[N];
int ans,mod;

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		vis[a[i]]++;
	}
	if(vis[a[n]]==n){
		cout<<0;
		return 0;
	}
	sort(a+1,a+n+1);
	int j=a[n]-a[n-1];
			for(int i=1;i<=n;i++){
				j*=i;
				m-=j;
				if(m>0){
					ans++;
				}
			}
			
	cout<<ans;
	return 0;
} 
