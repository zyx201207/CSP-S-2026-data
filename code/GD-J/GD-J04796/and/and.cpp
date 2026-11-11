#include<bits/stdc++.h>
using namespace std;
int n,m;
long long ans=0,a[200010],b[200010];
bool vis[200010];
void f(int d){
	if(d==m){
		long long sum=b[1]&b[2];
		for(int i=3;i<=m;i++){
			sum=sum&b[i];
		}
		ans=max(ans,sum);
		return;
	}
	for(int i=d;i<=n;i++){
		if(vis[i]==0){
			b[d]=a[i];
			vis[i]=1;
			f(d++);
			vis[i]=0;
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
	}
	memset(vis,0,n);
	f(1);
	cout<<ans;
	return 0;
}
