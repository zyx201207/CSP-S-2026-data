#include<bits/stdc++.h>
#define ll long long
#define inc(i,l,r) for(int i=l;i<=r;++i)
#define dec(i,r,l) for(int i=r;i>=l;--i)
using namespace std;
const int N=2e5+10;
ll a[N],n,m;
ll maxn=0;
void dfs(int depth,ll now,int start){
	if(n-start+1<m-depth+1)return;
	if(depth==m+1)maxn=max(maxn,now);
	if(depth==1){
		inc(i,start,n){
			dfs(depth+1,a[i],i+1);
		}
	}
	inc(i,start,n){
		dfs(depth+1,now&a[i],i+1);
	}
}
bool vis[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	//n=65536,m=16384;
	inc(i,1,n)cin>>a[i];
	if(n<=20){
		if(m!=1)dfs(1,0,1);
		else{
			maxn=0;
			inc(i,1,n){
				maxn=max(maxn,a[i]);
			}
			cout<<maxn;
			return 0;
		}
		cout<<maxn;
		return 0;
	}
	if(m==1){
		maxn=0;
		inc(i,1,n){
			maxn=max(maxn,a[i]);
		}
		cout<<maxn;
		return 0;
	}
	ll now=0,maxi=0;
	inc(i,1,m){
		maxn=0;
		if(i==1){
			inc(i,1,n){
				if(a[i]>now){
					now=a[i];
					maxi=i;
				}
			}
		}
		else{
			inc(i,1,n){
				if(!vis[i]&&(now&a[i])>maxn){
					maxn=now&a[i];
					maxi=i;
				}
			}
		}
		if(i!=1)now=maxn;
		vis[maxi]=1;
	}
	cout<<now;
}
