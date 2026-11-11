#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
	ll f=1,x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int c,t,n,sum,ans;
ll a[2000005],d;
void dfs(ll now,ll to,ll dep,ll depth){
	if(dep==depth) return;
	if(a[to]-a[now]<=d){
		sum++;
		return;
	}	 
	for(int pos=now+1;pos<=n&&a[pos]-a[now]<=d;pos++){
		dfs(pos,to,dep+1,depth);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		n=read();d=read();memset(a,0,sizeof(a));ans=0;
		for(int i=1;i<=n;i++) a[i]=read();
		for(int i=1;i<=n;i++){
			for(int j=i+2;j<=n;j++){
				int k=1;sum=0;
				while(sum==0){
					dfs(i,j,0,k);
					k++;if(k>n-j+1) break;
				} 
				if(sum==2){
					ans++;
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
