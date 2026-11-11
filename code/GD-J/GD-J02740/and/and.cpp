#include<bits/stdc++.h>
using namespace std;
long long m,n,ans,maxn;
long long a[200005];
long long vis[200005];
void jg(int d){
	if(d==m+1){
		ans=max(ans,maxn);
		return;
	}
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		if(d==1){
			maxn=a[i];
			vis[i]=1;
			jg(d+1);
			vis[i]=0;
		}
		else{
			int t=maxn;
			maxn&=a[i];
			vis[i]=1;
			jg(d+1);
			vis[i]=0;
			maxn=t;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	jg(1);
	cout<<ans;
	return 0;
} 
