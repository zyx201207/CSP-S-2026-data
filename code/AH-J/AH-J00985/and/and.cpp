#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string ikun="woshixiaohezi";//I'm true ikun
const int maxn=1e6+10;
ll n,m,a[maxn],e[300000][30],k,x[maxn],len,vis[maxn],res,cnt,ans=-1,sum;
void qwq(){
	for(int i=1;i<=n;i++){
		k=a[i];
		x[i]=0;
		while(k){
			x[i]++;
			e[i][x[i]]=k%2;
			k/=2;
		}
		len=max(len,x[i]);
	}
}
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		vis[i]=1;
	}
	cnt=n;
	qwq();
	for(int j=len;j>=1;j--){
		res=0;
		for(int i=1;i<=n;i++){
			if(vis[i]==1){
				if(e[i][j]==1)res++;
			}
			if(res==m){
				for(int i=1;i<=n;i++)if(e[i][j]==0)vis[i]=0;
				break;
			}
			if(res>m){
				sum=0;
				for(int i=1;i<=n;i++){
					if(e[i][j]==0&&vis[i]==1){
						vis[i]=2;
						sum++;
					}
				}
				if(cnt-sum>=m)cnt-=sum;
				else for(int i=1;i<=n;i++)if(vis[i]==2)vis[i]=1;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(vis[i]==1){
			if(ans==-1)ans=a[i];
			else ans=ans&a[i];
		}
	}
	cout<<ans;
}
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    solve();
    return 0;
}
//Trick||Treat!
