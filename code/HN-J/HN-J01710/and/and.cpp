#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=1e6+5;
int a[M],n,b[M],m,ans,vis[M],k[M];
vector<int>v[M];
int chai(int x,int id){
	for(int i=0;i<=30;i++){
		if(x<(1<<i)){
			break;
		}
		if(x&(1<<i)){
			b[i]++;
			v[i].push_back(id);
		}
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		chai(a[i],i);
	}
	int flag=0;
	for(int i=30;i>=0;i--){
		if(b[i]>=m){
			if(!flag){
				flag=1;
				for(int j:v[i]){
					vis[j]=1;
				}
				ans+=(1<<i);
			}
			else{
				for(int j=1;j<=n;j++){
					k[j]=0;
				}
				int res=0;
				for(int j:v[i]){
					if(!vis[j]){
						continue;
					}
					k[j]=1;
					res++;
				}
				for(int j=1;j<=n;j++){
					if(vis[j]&&!k[j]){
						vis[j]=0;
					}
				}
				if(res>=m){
					ans+=(1<<i);
				}
			}
			
		}
	}
	cout<<ans<<'\n';
	return 0;
}

