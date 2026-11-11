#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],t,sum[300005];
bool vis[500005];
vector<long long>v[300005];
bool check(long long x,long long y,long long z){
	for(int i=0;i<v[z].size();i++){
		if(v[z][i]>=x && v[z][i]<=y && vis[v[z][i]]==0){
			t=v[z][i];
			return true;
		}
	}
	return false;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		v[a[i]].push_back(i);
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(check(i,j-1,a[j])==true){
				for(int k=t;k<j;k++){
					vis[k]=1;
				}
			}
		}
		for(int j=i;j<=n;j++){
			if(vis[j]==0) sum[a[j]]++;
			vis[j]=0;
		}
	}
	for(int i=1;i<=m;i++){
		printf("%lld ",sum[i]);
	}
	return 0;
}
