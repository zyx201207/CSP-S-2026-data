#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=2e5+10;
ll n,m,maxn;
ll a[N],vis[N];
void bfs(int i,int cnt){
	if(i==n+1)return;
	if(cnt==m){
		bool kkk=0;
		ll k=0;
		for(int j=0;j<n;j++){
			if(vis[j]){
				if(!kkk){
					kkk=1;
					k=a[j];
				}
				k=k&a[j];
			}
		}
		maxn=max(maxn,k);
		return;
	}
	vis[i]=1;
	bfs(i+1,cnt+1);
	vis[i]=0;
	bfs(i+1,cnt);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie();
	cout.tie();
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(m==1){
		for(int i=0;i<n;i++){
			maxn=max(maxn,a[i]);
		}
	}else if(m==n){
		maxn=a[0];
		for(int i=1;i<n;i++){
			maxn=maxn&a[i];
		}
	}
	else if(m==2){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				maxn=max(maxn,a[i]&a[j]);
			}
		}
	}else{
		bfs(0,0);
	}
	cout<<maxn;
}
