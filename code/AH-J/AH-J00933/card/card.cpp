#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=5e5+10,M=3e5+10;
LL n,m,a[N],cnt[M],id[M];
bool flag[M];
vector<int> v[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	v[n].push_back(a[n]);
	id[a[n]]=n;flag[a[n]]=1;
	for(int i=n-1;i>=1;i--){
		if(!flag[a[i]]){
			flag[a[i]]=1;
			id[a[i]]=i;
			v[i]=v[i+1];
			v[i].push_back(a[i]);
		}	
		else{
			v[i]=v[id[a[i]]+1];
			v[i].push_back(a[i]);
		}	
	}	
	for(int i=1;i<=n;i++){
		for(int j=0;j<v[i].size();j++){
			cnt[v[i][j]]++;
		}
	}	
	for(int i=1;i<=m;i++) printf("%lld ",cnt[i]);
	return 0;
}
