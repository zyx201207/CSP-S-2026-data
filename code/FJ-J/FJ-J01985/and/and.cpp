#include<bits/stdc++.h>
using namespace std;
const int N=2*1e5+50;
int n,m;
int a[N],b[N],mm[N];
int ans=0,maxn=0;
bool pd[N];
void dfs(int k){
	if(k>m){
		int tot=b[1];
		for(int i=1;i<k;i++)
			tot=tot&b[i];
		ans=max(ans,tot);
		return ;
	}
	for(int i=1;i<=n;i++){
		if(!pd[i]){
			b[k]=a[i];pd[i]=1;
			dfs(k+1);
			b[k]=0;pd[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	}
	if(m==1){
		cout<<maxn;
		exit(0);
	}
	if(m==n){
		for(int i=1;i<=n;i++)
			a[1]=a[i]&a[1];
		cout<<a[1];
		exit(0);
	}
	dfs(1);
	cout<<ans;
	return 0;
}