#include<bits/stdc++.h>
using namespace std;
long long a[100001],maxx,b[100001];
long long n,k;
bool vis[100001];
void dfs(int x,int st){
	if(x>k){
		long long s=b[1];
		for(long long i=2;i<=x;i++)s&=b[i];
		maxx=max(maxx,s);
	}
	for(long long i=st;i<n;i++){
		if(vis[i]==0){
			vis[i]=1;
			b[x]=a[i];
			dfs(x+1,st+1);
			vis[i]=0;
		}
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>k;
	for(long long i=0;i<n;i++)scanf("%lld",&a[i]);
	dfs(1,0);
	cout<<maxx;
	return 0;
} 
