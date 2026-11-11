#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200005];
bool f[200005];
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		f[i]=1; 
	}
	int ans=0;
	for(int w=30;w>=0;w--){
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(!f[i])continue;
			if((a[i]&(1<<w)))cnt++;
		}
		if(cnt>=m){
			for(int i=1;i<=n;i++){
				if(!f[i])continue;
				if((a[i]&(1<<w)))f[i]=1;
				else f[i]=0;
			}
			ans+=(1<<w);
		}
	}
	cout<<ans;
	return 0;
}
