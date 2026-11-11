#include<bits/stdc++.h>
using namespace std;
long long a[500005],aa,fa,n,m,i,j,ans,num[300005],vis[300005],cnt;
vector<long long> v[300005];
void di(long long aa,long long fa,long long x){
	for(auto x:v[aa]){
		if(x==fa)continue;
		di(x,aa,0);
		num[aa]+=num[x];
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++){
		cin>>a[i];
		num[a[i]]++;
	}
	for(i=n;i>=1;i--){
		if(!vis[a[i]]){
			vis[a[i]]=1;
			v[a[i+1]].push_back(a[i]);
		}
	}
	di(a[n],0,0);
	for(i=1;i<=m;i++){
		cout<<num[i]<<' ';
	}
	return 0;
}
