#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int f[N][45],l[N],a[N];
bool vis[N],t[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	int n,m,maxn=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int x;
		cin>>a[i];
		x=a[i];
		while(x){
			f[i][++l[i]]=x%2;
			x/=2;
		}
		maxn=max(maxn,l[i]);
	}
	int res=n;
	for(int i=maxn;i>=1;i--){
		int s=0;
		for(int j=1;j<=n;j++){
			if(!vis[j]){
				if(f[j][i]==1) s++;
			}
		}
		if(s>=m){
			res=s;
			for(int j=1;j<=n;j++){
				if(!vis[j]){
					if(f[j][i]==0) vis[j]=1;
				}
			}
		}
		if(res==m){
			break;
		}
	}
	int ans=-1,cnt=0;
	for(int i=1;i<=n&&cnt<m;i++){
		if(!vis[i]){
			if(ans==-1) ans=a[i];
			else ans&=a[i];
		}
	}
	cout<<ans;
	return 0;
} 
