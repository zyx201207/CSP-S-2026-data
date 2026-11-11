#include<bits/stdc++.h>
using namespace std;
struct node{
	long long v;
	long long w;
};
long long w[500005];
long long k[505];
map<pair<long long,long long>,long long> ans;
void Floyed(long long m){
	for(long long i=1;i<=m;i++){
		for(long long j=1;j<=m;j++){
			for(long long k=1;k<=m;k++){
				ans[{j,i}]=ans[{i,j}]=min(ans[{i,j}],ans[{i,k}]+ans[{k,j}]);
			}
		}
	}
}
int main(){
    freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=m;i++)
		cin>>w[i];
	for(long long i=1;i<=n+m;i++){
		for(long long j=1;j<=n+m;j++)
			ans[{i,j}]=INT_MAX;
		ans[{i,i}]=0;
	}
	for(long long i=1;i<=n;i++){
		cin>>k[i];
		long long last_a,last_b;
		for(long long j=1;j<=k[i];j++){
			long long a,b;
			cin>>a>>b;
			ans[{a,m+i}]=b;
			ans[{m+i,a}]=b;
		}
	}
	Floyed(m+n);
	while(q--){
		long long l,r;
		cin>>l>>r;
		cout<<ans[{l,r}]+w[l]+w[r]<<endl;
	}
	return 0;
}
