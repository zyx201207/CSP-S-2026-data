#include<bits/stdc++.h>
#define ll long long
#define N 500001
using namespace std;
ll n,m,a[N],now[N],ans[N],nxt[N],num[N],cnt;
bool vis[N],flag=true;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i-1]>a[i]) flag=false;
		nxt[now[a[i]]]=i;
		now[a[i]]=i;
	}
	if(flag){
		for(int i=1;i<n;i++)
		if(a[i+1]!=a[i]) ans[a[i]]=i;
		ans[a[n]]=n;
		for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
		return 0;
	}
	if(m==1){
		cout<<n<<endl;
		return 0;
	}
	if(m==2){
		for(int i=1;i<=n;i++)
		if(a[i]!=a[n]) ans[a[i]]++;
		ans[a[n]]=n; 
		for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
		return 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++) vis[j]=false;
		for(int j=i;j<=n;j++){
			if(vis[a[j]]){
				for(;cnt>0;cnt--){
					if(num[cnt]==a[j]) break;
					ans[num[cnt]]--;
					vis[num[cnt]]=false;
				} 
			}else{
				ans[a[j]]++;
				num[++cnt]=a[j];
				vis[a[j]]=true;
			}
		}
		cnt=0;
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
