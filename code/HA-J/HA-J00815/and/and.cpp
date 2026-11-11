#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+5;
int n,m,a[N],sz[N],ans,mx,mk[N];
bool lg[N][35],vis[N];
int lgg(int x,int id){
	int i=0;
	while(x){
		lg[id][i++]=x&1;
		x>>=1;
	}return i-1;
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sz[i]=lgg(a[i],i);
		mx=max(mx,sz[i]);
	}
	for(int i=mx;i>=0;i--){
		int res=0,idx=0;
		for(int j=1;j<=n;j++){
			if(vis[j])continue;
			if(lg[j][i])res++;
			else mk[++idx]=j;
		}if(res>=m){
			ans+=1<<i;
			for(int j=1;j<=idx;j++)vis[mk[j]]=1;
		}
	}cout<<ans;
	return 0;
}
