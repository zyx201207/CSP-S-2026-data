#include<bits/stdc++.h>
using namespace std;
long long n,m,a[200002],sum[200002],c[200002];
void solve(int k){
	stack<int>b;
	for(int i=1;i<=n;i++)c[i]=0;
	for(int i=k;i<=n;i++){
		if(c[a[i]]==0){
			c[a[i]]=1;
			b.push(a[i]);
		}else{
			while(!b.empty()&&b.top()!=a[i]){
				c[b.top()]=0;
				b.pop();
			}
		}
	}
	for(int i=1;i<=m;i++){
		sum[i]+=c[i];
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		solve(i);
	}
	for(int i=1;i<=m;i++)cout<<sum[i]<<" ";
	return 0;
}
