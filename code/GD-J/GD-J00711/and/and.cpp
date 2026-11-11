#include<bits/stdc++.h>
#define ll long long
#define N 200010
using namespace std;
int n,m,check[N];
ll tot=-1;
ll a[N];
void DFS(int x,int cnt,ll sum){
	if(x>n+1) return;
	else if(cnt==m){
		if(sum>tot) tot=sum;
		return;
	}
	if(sum==-1){
		check[cnt]=a[x];
		DFS(x+1,cnt+1,a[x]);
		DFS(x+1,cnt,-1);
	}else{
		check[cnt]=(a[x]&sum);
		DFS(x+1,cnt+1,(a[x]&sum));
		DFS(x+1,cnt,sum);
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1){
		ll ans=-1;
		for(int i=1;i<=n;i++) ans=max(ans,a[i]);
		cout<<ans;
	}
	else if(m==n){
		ll ans=a[1];
		for(int i=2;i<=n;i++) ans&=a[i];
		cout<<ans;
	}
	else if(m==2){
		ll ans=-1;
		for(int i=1;i<=n;i++){
			for(int j=1;j!=i&&j<=n;j++) ans=max(ans,(a[i]&a[j]));
		}
		cout<<ans;
	}
	else{
		DFS(1,0,-1);
		cout<<tot;
	}
	return 0;
}
