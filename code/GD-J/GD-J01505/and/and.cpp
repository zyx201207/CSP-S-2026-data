#include<bits/stdc++.h>
using namespace std;
vector<long long> v;
long long a[200010];
long long n,m,ans;
void dfs(long long idx){
	if(v.size()>=m){
		long long t=LONG_LONG_MAX;
		for(auto i:v){
			t&=a[i];
		} 
		ans=max(ans,t);
		return ;
	}
	for(long long i=idx+1;i<=n;i++){
		v.push_back(i);
		dfs(i);
		v.pop_back();
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	dfs(0);
	printf("%d",ans);
	return 0;
} 
