#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e6+10;
int n,l[maxn],r[maxn],minn,cnt;
ll d,x[maxn],ans;
void dfs(int u,int v,int len){
	if(r[u]>=v){
		len++;
		if(len<minn) minn=len,cnt=1;
		else if(len==minn) cnt++;
		return;
	}
	for(int i=u+1;i<=r[u];i++){
		dfs(i,v,len+1);
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	int C,T; cin>>C>>T;
	while(T--){
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>x[i];
		int p=1;
		for(int i=1;i<=n;i++){
			while(p<i&&x[i]-x[p]>d) p++;
			l[i]=p;
		}
		p=n;
		for(int i=n;i>=1;i--){
			while(p>i&&x[p]-x[i]>d) p--;
			r[i]=p;
		} ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				minn=maxn,cnt=0;
				dfs(i,j,0);
				if(cnt==2){
					ans++;
				}
			}
		}
		cout<<ans<<'\n';
	}
	fclose(stdin); fclose(stdout);
	return 0;
}
