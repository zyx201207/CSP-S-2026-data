#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define LL long long
#define inf 0x3f
#define Inf 0x3f3f3f3f3f3f3f3f
const int N=2e5+5;
int n,m,len,L;
ll cur;
int a[N];
int f[N][40];
int c[N];
int sum;
int nxt[N],pre[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		int k=a[i];
		int t=0;
		while(k){
			c[++t]=k%2;
			k/=2;
		}
		len=max(len,t);
		for(int j=1;j<=t;j++){
			f[i][j]=c[j];
		}
	}
	L=n;
	for(int i=1;i<=n;i++) nxt[i]=i;
	for(int j=len;j>=1;j--){
		int ans=0;
		for(int i=1;i<=L;i++){
			if(f[nxt[i]][j]==1) {
				ans++;
			}
		}
		if(ans>=m) {
			cur=cur+(1<<(j-1)); 
			int mu=0;
			for(int i=1;i<=L;i++){
				if(f[nxt[i]][j]==1){
					pre[++mu]=nxt[i];
				}
			} 
			for(int i=1;i<=mu;i++) nxt[i]=pre[i];
			L=mu;
		}
	}
	cout<<cur;
	return 0;
}
